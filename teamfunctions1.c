#include "main.h"
/**
 * printerunsigned - Prints an unsigned number
 * @typ: List a of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of char
 */
int printerunsigned(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	int i = buffy_sz - 2;
	unsigned long intnumber = va_arg(typ, unsigned long int);

	num = convert_sz_unsgnd(num, sz);

	if (num == 0)
		bff[i--] = '0';

	bff[buffy_sz - 1] = '\0';

	while (num > 0)
	{
		bff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wrunsgnd(0, i, bff, fl, wd, prs, sz));
}
/**
 * printeroctal - Prints an unsigned number in octal notation
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars
 */
int printeroctal(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{

	int i = buffy_sz - 2;
	unsigned long intnumber = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wd);

	num = convert_sz_unsgnd(num, sz);

	if (num == 0)
		bff[i--] = '0';

	bff[buffy_sz - 1] = '\0';

	while (num > 0)
	{
		bff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (fl & F_HASH && init_num != 0)
		bff[i--] = '0';

	i++;

	return (wrunsgnd(0, i, bff, fl, wd, prs, sz));
}
/**
 * printerhexadecimal - Prints an unsigned number in hexadecimal notation
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars printed
 */
int printerhexadecimal(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	return (printerhexa(typ, "0123456789abcdef", bff,
		fl, 'x', wd, prs, sz));
}
/**
 * printerhexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars
 */
int printerhexa_upper(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	return (printerhexa(typ, "0123456789ABCDEF", bff,
		fl, 'X', wd, prs, sz));
}
/**
 * printerhexa - Prints a hexadecimal number
 * @typ: Lista of arguments
 * @map_to: Array of values to map the number to
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @flag_ch: Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * @sz: sz specific
 * Return: Number of char
 */
int printerhexa(va_list typ, char map_to[], char bff[],
	int fl, char flag_ch, int wd, int prs, int sz)
{
	int i = buffy_sz - 2;
	unsigned long intnumber = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wd);

	num = convert_sz_unsgnd(num, sz);

	if (num == 0)
		bff[i--] = '0';

	bff[buffy_sz - 1] = '\0';

	while (num > 0)
	{
		bff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (fl & F_HASH && init_num != 0)
	{
		bff[i--] = flag_ch;
		bff[i--] = '0';
	}

	i++;

	return (wrunsgnd(0, i, bff, fl, wd, prs, sz));
}
