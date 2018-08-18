#pragma once
#include "Utils.h"


// ��������� ���� ��� ����� � ��������� ������ --
// �������� � ����������� �� �����������
typedef float float32_t;
typedef double float64_t;

#define pack754_32(f) (pack754((f), 32, 8))
#define pack754_64(f) (pack754((f), 64, 11))
#define unpack754_32(i) (unpack754((i), 32, 8))
#define unpack754_64(i) (unpack754((i), 64, 11))

uint64_t pack754(long double f, unsigned bits, unsigned expbits)
{
	long double fnorm;
	int shift;
	long long sign, exp, significand;
	unsigned significandbits = bits - expbits - 1; // -1 ��� ���� �����

	if (f == 0.0) return 0; // ������������� ���� ������ ������

							// �������� ���� � ����� ������������
	if (f < 0) { sign = 1; fnorm = -f; }
	else { sign = 0; fnorm = f; }

	// ������ ��������������� ����� f � �������� ����������
	shift = 0;
	while (fnorm >= 2.0) { fnorm /= 2.0; shift++; }
	while (fnorm < 1.0) { fnorm *= 2.0; shift--; }
	fnorm = fnorm - 1.0;

	// ���������� �������� ����� (��-float) �������� ������
	significand = fnorm * ((1LL << significandbits) + 0.5f);

	// �������� ����������
	exp = shift + ((1 << (expbits - 1)) - 1); // shift + bias

											  // ���������� �������� ��������
	return (sign << (bits - 1)) | (exp << (bits - expbits - 1)) | significand;
}

long double unpack754(uint64_t i, unsigned bits, unsigned expbits)
{
	long double result;
	long long shift;
	unsigned bias;
	unsigned significandbits = bits - expbits - 1; // -1 ��� ���� �����

	if (i == 0) return 0.0;

	// pull the significand
	result = (i&((1LL << significandbits) - 1)); // �����
	result /= (1LL << significandbits); // ������������ ������� �� float
	result += 1.0f; // ���������� �������

					// ����������� � �����������
	bias = (1 << (expbits - 1)) - 1;
	shift = ((i >> significandbits)&((1LL << expbits) - 1)) - bias;
	while (shift > 0) { result *= 2.0; shift--; }
	while (shift < 0) { result /= 2.0; shift++; }

	// �������� ���������
	result *= (i >> (bits - 1)) & 1 ? -1.0 : 1.0;

	return result;
}

/*
** packi16() -- ��������� 16-������ ����� � ����� char[] (������ �� htons())
*/
void packi16(unsigned char *buf, unsigned int i)
{
	*buf++ = i >> 8; *buf++ = i;
}

/*
** packi32() -- ��������� 32-������ ����� � ������ char[] (������ �� htonl())
*/
void packi32(unsigned char *buf, unsigned long i)
{
	*buf++ = i >> 24; *buf++ = i >> 16;
	*buf++ = i >> 8;  *buf++ = i;
}

/*
** unpacki16() -- ������������� 16-������ ����� �� ������� char (��� ntohs())
*/
unsigned int unpacki16(unsigned char *buf)
{
	return (buf[0] << 8) | buf[1];
}

/*
** unpacki32() -- ������������� 32-������ ����� �� ������� char (��� ntohl())
*/
unsigned long unpacki32(unsigned char *buf)
{
	return (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
}

/*
** pack() -- ��������� � ����� ������, ���������� � ������ "format"
**
**  h - 16-bit              l - 32-bit
**  c - 8-bit char          f - float, 32-bit
**  s - string (������������� ����������� ������ � 16 ���)
*/
int32_t pack(unsigned char *buf, char *format, ...)
{
	va_list ap;
	int16_t h;
	int32_t l;
	int8_t c;
	float32_t f;
	char *s;
	int32_t size = 0, len;

	va_start(ap, format);

	for (; *format != ' '; format++) {
		switch (*format) {
		case 'h': // 16-bit
			size += 2;
			h = (int16_t)va_arg(ap, int);
			packi16(buf, h);
			buf += 2;
			break;

		case 'l': // 32-bit
			size += 4;
			l = va_arg(ap, int32_t);
			packi32(buf, l);
			buf += 4;
			break;

		case 'c': // 8-bit
			size += 1;
			c = (int8_t)va_arg(ap, int);
			*buf++ = (c >> 0) & 0xff;
			break;

		case 'f': // float
			size += 4;
			f = (float32_t)va_arg(ap, double);
			l = pack754_32(f); // convert to IEEE 754
			packi32(buf, l);
			buf += 4;
			break;

		case 's': // string
			s = va_arg(ap, char*);
			len = strlen(s);
			size += len + 2;
			packi16(buf, len);
			buf += 2;
			memcpy(buf, s, len);
			buf += len;
			break;
		}
	}

	va_end(ap);

	return size;
}

/*
** unpack() -- ������������� � ����� ������, ���������� � ������ "format"
*/
void unpack(unsigned char *buf, char *format, ...)
{
	va_list ap;
	int16_t *h;
	int32_t *l;
	int32_t pf;
	int8_t *c;
	float32_t *f;
	char *s;
	int32_t len, count, maxstrlen = 0;

	va_start(ap, format);

	for (; *format != ' '; format++) {
		switch (*format) {
		case 'h': // 16-bit
			h = va_arg(ap, int16_t*);
			*h = unpacki16(buf);
			buf += 2;
			break;

		case 'l': // 32-bit
			l = va_arg(ap, int32_t*);
			*l = unpacki32(buf);
			buf += 4;
			break;

		case 'c': // 8-bit
			c = va_arg(ap, int8_t*);
			*c = *buf++;
			break;

		case 'f': // float
			f = va_arg(ap, float32_t*);
			pf = unpacki32(buf);
			buf += 4;
			*f = unpack754_32(pf);
			break;

		case 's': // string
			s = va_arg(ap, char*);
			len = unpacki16(buf);
			buf += 2;
			if (maxstrlen > 0 && len > maxstrlen) count = maxstrlen - 1;
			else count = len;
			memcpy(s, buf, count);
			s[count] = 0;
			buf += len;
			break;

		default:
			if (isdigit(*format)) { // ����������� ������������ ������ ������
				maxstrlen = maxstrlen * 10 + (*format - '0');
			}
		}

		if (!isdigit(*format)) maxstrlen = 0;
	}

	va_end(ap);
}


//����� ������ � �������
void Print(char *message) {
	printf("%s\n", message);
}

