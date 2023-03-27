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
	int sip, j;
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
				printf("%c", sip);
				format++;
				break;
			}
			
			case 's':
			{
				for (j = 0; j < '\0'; j++)
				{
					len += 1;
				}
				Str = va_arg(arg, char*);
				printf("%s", Str);
				format++;
				break;
			}

			case '%':
			{
				printf("%%");
				len += 1;
				format++;
				break;
			}

			default:
			{
				printf("%c", format[i]);
				len += 1;
				format++;
				break;
			}
		}
	}
	va_end(arg);

	return (len);
}
