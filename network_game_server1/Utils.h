#pragma once
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


/*
** packi16() -- сохраняет 16-битное число в буфер char[] (похоже на htons())
*/
void packi16(unsigned char *buf, unsigned int i);

/*
** packi32() -- сохраняет 32-битное число в массив char[] (похоже на htonl())
*/
void packi32(unsigned char *buf, unsigned long i);

/*
** unpacki16() -- распаковывает 16-битное число из массива char (как ntohs())
*/
unsigned int unpacki16(unsigned char *buf);

/*
** unpacki32() -- распаковывает 32-битное число из массива char (как ntohl())
*/
unsigned long unpacki32(unsigned char *buf);


/*
** pack() -- сохраняет в буфер данные, переданные в строке "format"
**
**  h - 16-bit              l - 32-bit
**  c - 8-bit char          f - float, 32-bit
**  s - string (автоматически добавляется длинна в 16 бит)
*/
int32_t pack(unsigned char *buf, char *format, ...);

/*
** unpack() -- распаковывает в буфер данные, переданные в строке "format"
*/
void unpack(unsigned char *buf, char *format, ...);

//Вывод текста в консоль
void Print(char *message);