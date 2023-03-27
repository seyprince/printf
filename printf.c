#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - print a string
 * @format: string to consider
 * Return: 0 or -1
 */

int _printf(const char *format, ...)
{
	va_list arg;
	unsigned int i = 0, len = 0;
	char *Str, j;

va_start(arg, format);
if (format)
{
for (i = 0; format && format[i]; i++)
{
if (format[i] == '%')
printf("%%");
}
if (format[i] == 'c')
{
len += 1;
printf("%s", va_arg(arg, int));
}
if (format[i] == 's')
{
for (j = 0; j < '\0'; j++)
{
len += 1;
}
Str = va_arg(arg, char*);
printf("%s", Str);
}
}
va_end(arg);
return (len);
}
