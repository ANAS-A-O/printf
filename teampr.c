#include "main.h"
/**
 * teampr - Calculates the prs for printing
 * @format: Formatted string in which
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: prs.
 */
int teampr(const char *format, int *i, va_list list)
{
	int crri = *i + 1;
	int prs = -1;

	if (format[crri] != '.')
		return (prs);

	prs = 0;

	for (crri += 1; format[crri] != '\0'; crri++)
	{
		if (digitability(format[crri]))
		{
			prs *= 10;
			prs += format[crri] - '0';
		}
		else if (format[crri] == '*')
		{
			crri++;
			prs = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = crri - 1;

	return (prs);
}
