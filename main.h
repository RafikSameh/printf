#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
char * _itoa(int i, char *strout, int base);
char *_strrev (char *str);

#endif
