#include "main.h"
/**
 * printerchar - Prints a char
 * @typ: List a of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars
 */
int printerchar(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	char c = va_arg(typ, int);

	return (hdl_wrchar(c, bff, fl, wd, prs, sz));
}
/**
 * printerstring - Prints a string
 * @typ: List a of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd.
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars printed
 */
int printerstring(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	int lgth = 0, i;
	char *str = va_arg(typ, char *);

	UNUSED(bff);
	UNUSED(fl);
	UNUSED(wd);
	UNUSED(prs);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (prs >= 6)
			str = "      ";
	}

	while (str[lgth] != '\0')
		lgth++;

	if (prs >= 0 && prs < lgth)
		lgth = prs;

	if (wd > lgth)
	{
		if (fl & F_MINUS)
		{
			write(1, &str[0], lgth);
			for (i = wd - lgth; i > 0; i--)
				write(1, " ", 1);
			return (wd);
		}
		else
		{
			for (i = wd - lgth; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], lgth);
			return (wd);
		}
	}

	return (write(1, str, lgth));
}
/**
 * printerpercent - Prints a percent sign
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd.
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars
 */
int printerpercent(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	UNUSED(typ);
	UNUSED(bff);
	UNUSED(fl);
	UNUSED(wd);
	UNUSED(prs);
	UNUSED(sz);
	return (write(1, "%%", 1));
}
/**
 * printerint - Print int
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd.
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars
 */
int printerint(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	int i = buffy_sz - 2;
	int maybenegative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = convert_sz_number(n, sz);

	if (n == 0)
		bff[i--] = '0';

	bff[buffy_sz - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		maybenegative = 1;
	}

	while (num > 0)
	{
		bff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wrnumber(maybenegative, i, bff, fl, wd, prs, sz));
}
/**
 * printerbinary - Prints an unsigned number
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd.
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Numbers of char printed.
 */
int printerbinary(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(bff);
	UNUSED(fl);
	UNUSED(wd);
	UNUSED(prs);
	UNUSED(sz);

	n = va_arg(typ, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
