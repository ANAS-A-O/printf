#include "main.h"
/**
 * hdl_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @rang: rang.
 * @bff: bff array to hdl print.
 * @fl: Calculates active fl
 * @wd: get wd.
 * @prs: prs specification
 * @sz: sz specifier
 * Return: 1 or 2;
 */
int hdl_print(const char *fmt, int *rang, va_list list, char bff[],
	int fl, int wd, int prs, int sz)
{
	int i, unknow_len = 0, charsprinted = -1;
	fmt_t fmt_typ[] = {
		{'c', printerchar}, {'s', printerstring}, {'%', printerpercent},
		{'i', printerint}, {'d', printerint}, {'b', printerbinary},
		{'u', printerunsigned}, {'o', printeroctal}, {'x', printerhexadecimal},
		{'X', printerhexa_upper}, {'p', printerpointer}, {'S', printernon_printable},
		{'r', printerreverse}, {'R', printerrot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_typ[i].fmt != '\0'; i++)
		if (fmt[*rang] == fmt_typ[i].fmt)
			return (fmt_typ[i].fn(list, bff, fl, wd, prs, sz));

	if (fmt_typ[i].fmt == '\0')
	{
		if (fmt[*rang] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*rang - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wd)
		{
			--(*rang);
			while (fmt[*rang] != ' ' && fmt[*rang] != '%')
				--(*rang);
			if (fmt[*rang] == ' ')
				--(*rang);
			return (1);
		}
		unknow_len += write(1, &fmt[*rang], 1);
		return (unknow_len);
	}
	return (charsprinted);
}

