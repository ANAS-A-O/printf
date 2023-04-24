#include "main.h"
/**
 * printerpointer - Prints the value of a pointer
 * @typ: List a of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars
 */
int printerpointer(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	char teamc = 0, paddinng = ' ';
	int rang = buffy_sz - 2, lgth = 2, paddinng_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(typ, void *);

	UNUSED(wd);
	UNUSED(sz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	bff[buffy_sz - 1] = '\0';
	UNUSED(prs);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		bff[rang--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		lgth++;
	}

	if ((fl & F_ZERO) && !(fl & F_MINUS))
		paddinng = '0';
	if (fl & F_PLUS)
		teamc = '+', lgth++;
	else if (fl & F_SPACE)
		teamc = ' ', lgth++;

	rang++;

	return (wrpointer(bff, rang, lgth,
		wd, fl, paddinng, teamc, paddinng_start));
}
/**
 * printernon_printable - Prints ascii codes in hexa of non printable chars
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Number of chars
 */
int printernon_printable(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(typ, char *);

	UNUSED(fl);
	UNUSED(wd);
	UNUSED(prs);
	UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (printability(str[i]))
			bff[i + offset] = str[i];
		else
			offset += hexastuff(str[i], bff, i + offset);

		i++;
	}

	bff[i + offset] = '\0';

	return (write(1, bff, i + offset));
}
/**
 * printerreverse - Prints reverse string.
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Numbers of chars printed
 */
int printerreverse(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	char *str;
	int i, count = 0;

	UNUSED(bff);
	UNUSED(fl);
	UNUSED(wd);
	UNUSED(sz);

	str = va_arg(typ, char *);

	if (str == NULL)
	{
		UNUSED(prs);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * printerrot13string - Print a string in rot13.
 * @typ: Lista of arguments
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd
 * @prs: prs specification
 * @sz: sz specifier
 * Return: Numbers of chars printed
 */
int printerrot13string(va_list typ, char bff[],
	int fl, int wd, int prs, int sz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);
	UNUSED(bff);
	UNUSED(fl);
	UNUSED(wd);
	UNUSED(prs);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
