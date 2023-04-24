#include "main.h"

/**
 * teamfl - Calculates active fl
 * @format: Formatted string in which
 * @i: take a parameter.
 * Return: fl:
 */
int teamfl(const char *format, int *i)
{
	int j, crri;
	int fl = 0;
	const char fl_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int fl_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (crri = *i + 1; format[crri] != '\0'; crri++)
	{
		for (j = 0; fl_CH[j] != '\0'; j++)
			if (format[crri] == fl_CH[j])
			{
				fl |= fl_ARR[j];
				break;
			}

		if (fl_CH[j] == 0)
			break;
	}

	*i = crri - 1;

	return (fl);
}
