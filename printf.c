#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - print a string
 * @format: string to consider
 * Return: 0 or -1
 */

int _printf(const char *format, ...)
{
	va_list arg;
	unsigned int i = 0, len = 0;
	int sip;
	char *Str;

	va_start(arg, format);
	if (format)
	{
		for (i = 0; format && format[i]; i++)
		{
			if (format[i] == '%')
				format++;
		}
		switch (format[i])
		{
			case 'c':
			{
				len = len + 1;
				sip = va_arg(arg, int);
				putchar(sip);
				break;
			}
			case 's':
			{
				Str = va_arg(arg, char*);
				len += strlen(Str);
				puts(Str);
				break;
			}
			case '%':
			{
				putchar('%');
				len += 1;
				break;
			}
			default:
			{
				putchar(format[i]);
				len += 1;
				break;
			}
		}
	}
	va_end(arg);

	return (len);
}
