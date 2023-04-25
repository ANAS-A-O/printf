#include "main.h"

void printerbff(char bff[], int *buffy_rang);
/**
 * _printf - Printf function
 * @format: format
 * Return:prtedchars.
 */
int _printf(const char *format, ...);
{
	int i, prted = 0, charsprinted = 0;
	int fl, wd, prs, sz, buffy_rang = 0;
	va_list list;
	char bff[buffy_sz];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (format[i] != '\0' && i = 0; format; i++)
	{
		if (format[i] != '%')
		{
			bff[buffy_rang++] = format[i];
			if (buffy_rang == buffy_sz)
				printerbff(bff, &buffy_rang);
			charsprinted++;
		}
		else
		{
			printerbff(bff, &buffy_rang);
			fl = teamfl(format, &i);
			wd = teamwd(format, &i, list);
			prs = teampr(format, &i, list);
			sz = teamsz(format, &i);
			++i;
			printed = hdl_print(format, &i, list, bff,
				fl, wd, prs, sz);
			if (printed == -1)
				return (-1);
			charsprinted += printed;
		}
	}
}
	printerbff(bff, &buffy_rang);

	va_end(list);

	return (charsprinted);
}
/**
* printerbff - Prints the contents
* @bff: Array of char
* @buffy_rang: rangex at which to add next char
*/
void printerbff(char bff[], int *buffy_rang)
{
	if (*buffy_rang > 0)
		write(1, &bff[0], *buffy_rang);

	*buffy_rang = 0;
}
