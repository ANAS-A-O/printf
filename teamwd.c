#include "main.h"

/**
 * teamwd - Calculates the wd for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: wd.
 */
int teamwd(const char *format, int *i, va_list list)
{
	int crri;
	int wd = 0;

	for (crri = *i + 1; format[crri] != '\0'; crri++)
	{
		if (digitability(format[crri]))
		{
			wd *= 10;
			wd += format[crri] - '0';
		}
		else if (format[crri] == '*')
		{
			crri++;
			wd = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = crri - 1;

	return (wd);
}

