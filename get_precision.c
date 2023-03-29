#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;
    char specifiers[] = "diouxXeEfFgG";
    int found_specifier = 0;
    int j = 0;

    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
        {
            found_specifier = 0;
            for (j = 0; specifiers[j] != '\0'; j++)
            {
                if (format[curr_i] == specifiers[j])
                {
                    found_specifier = 1;
                    break;
                }
            }
            if (found_specifier)
                break;
        }
    }

    *i = curr_i - 1;

    return (precision);
}

