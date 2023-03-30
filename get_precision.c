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
    char current_char = format[curr_i];

    if (current_char == '.')
    {
        precision = 0;
        current_char = format[++curr_i];

        if (current_char == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
        }
        else
        {
            while (is_digit(current_char))
            {
                precision = (precision * 10) + (current_char - '0');
                current_char = format[++curr_i];
            }
        }
    }

    *i = curr_i - 1;

    return precision;
}

