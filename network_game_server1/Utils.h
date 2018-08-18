#pragma once
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


/*
** packi16() -- ��������� 16-������ ����� � ����� char[] (������ �� htons())
*/
void packi16(unsigned char *buf, unsigned int i);

/*
** packi32() -- ��������� 32-������ ����� � ������ char[] (������ �� htonl())
*/
void packi32(unsigned char *buf, unsigned long i);

/*
** unpacki16() -- ������������� 16-������ ����� �� ������� char (��� ntohs())
*/
unsigned int unpacki16(unsigned char *buf);

/*
** unpacki32() -- ������������� 32-������ ����� �� ������� char (��� ntohl())
*/
unsigned long unpacki32(unsigned char *buf);


/*
** pack() -- ��������� � ����� ������, ���������� � ������ "format"
**
**  h - 16-bit              l - 32-bit
**  c - 8-bit char          f - float, 32-bit
**  s - string (������������� ����������� ������ � 16 ���)
*/
int32_t pack(unsigned char *buf, char *format, ...);

/*
** unpack() -- ������������� � ����� ������, ���������� � ������ "format"
*/
void unpack(unsigned char *buf, char *format, ...);

//����� ������ � �������
void Print(char *message);