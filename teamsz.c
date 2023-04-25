#include "main.h"

/**
 * teamsz - Calculates the sz to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: prs.
 */
int teamsz(const char *format, int *i)
{
	int crri = *i + 1;
	int sz = 0;

	if (format[crri] == 'l')
		sz = S_LONG;
	else if (format[crri] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = crri - 1;
	else
		*i = crri;

	return (sz);
}

