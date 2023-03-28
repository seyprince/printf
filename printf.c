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
	int len = 0;
	char *Str;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
		format++;
		switch (*format)
		{
			case 'c':
			{
				len++;
				printf("%c", va_arg(arg, int));
				break;
			}
			case 's':
			{
				Str = va_arg(arg, char*);
				len += strlen(Str);
				printf("%s", Str);
				break;
			}
			case '%':
			{
				putchar('%');
				len++;
				break;
			}
			default:
				break;
		}
		}
		else
		{
			putchar(*format);
			len++;
		}
		format++;
	}
	va_end(arg);
	return (len);
}
