#include "main.h"

/************* WRITE hdl *************/
/**
 * hdl_wrchar - Prints a string
 * @c: char typ.
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl.
 * @wd: get wd.
 * @prs: prs specifier
 * @sz: sz specifier
 *
 * Return: Number of chars printed.
 */
int hdl_wrchar(char c, char bff[],
	int fl, int wd, int prs, int sz)
{ /* char is stored at left and paddinngrang at bff's right */
	int i = 0;
	char paddinng = ' ';

	UNUSED(prs);
	UNUSED(sz);

	if (fl & F_ZERO)
		paddinng = '0';

	bff[i++] = c;
	bff[i] = '\0';

	if (wd > 1)
	{
		bff[buffy_sz - 1] = '\0';
		for (i = 0; i < wd - 1; i++)
			bff[buffy_sz - i - 2] = paddinng;

		if (fl & F_MINUS)
			return (write(1, &bff[0], 1) +
					write(1, &bff[buffy_sz - i - 1], wd - 1));
		else
			return (write(1, &bff[buffy_sz - i - 1], wd - 1) +
					write(1, &bff[0], 1));
	}

	return (write(1, &bff[0], 1));
}

/************* WRITE NUMBER *************/
/**
 * wrnumber - Prints a string
 * @maybenegative: Lista of arguments
 * @rang: char typ.
 * @bff: bff array to hdl print
 * @fl:  Calculates active fl
 * @wd: get wd.
 * @prs: prs specifier
 * @sz: sz specifier
 *
 * Return: Number of chars printed.
 */
int wrnumber(int maybenegative, int rang, char bff[],
	int fl, int wd, int prs, int sz)
{
	int lgth = buffy_sz - rang - 1;
	char paddinng = ' ', teamch = 0;

	UNUSED(sz);

	if ((fl & F_ZERO) && !(fl & F_MINUS))
		paddinng = '0';
	if (maybenegative)
		teamch = '-';
	else if (fl & F_PLUS)
		teamch = '+';
	else if (fl & F_SPACE)
		teamch = ' ';

	return (wrnum(rang, bff, fl, wd, prs,
		lgth, paddinng, teamch));
}

/**
 * wrnum - Write a number using a buffyfer
 * @rang: rangex at which the number starts on the bff
 * @bff: bff
 * @fl: fl
 * @wd: wd
 * @prec: prs specifier
 * @lgth: Number lgth
 * @paddinng: Pading char
 * @teamc: Extra char
 *
 * Return: Number ofprtedchars.
 */
int wrnum(int rang, char bff[],
	int fl, int wd, int prec,
	int lgth, char paddinng, char teamc)
{
	int i, paddinng_start = 1;

	if (prec == 0 && rang == buffy_sz - 2 && bff[rang] == '0' && wd == 0)
		return (0); /* printf(".0d", 0)  no char isprted*/
	if (prec == 0 && rang == buffy_sz - 2 && bff[rang] == '0')
		bff[rang] = paddinng = ' '; /* wd is displayed with paddinnging ' ' */
	if (prec > 0 && prec < lgth)
		paddinng = ' ';
	while (prec > lgth)
		bff[--rang] = '0', lgth++;
	if (teamc != 0)
		lgth++;
	if (wd > lgth)
	{
		for (i = 1; i < wd - lgth + 1; i++)
			bff[i] = paddinng;
		bff[i] = '\0';
		if (fl & F_MINUS && paddinng == ' ')
		{
			if (teamc)
				bff[--rang] = teamc;
			return (write(1, &bff[rang], lgth) + write(1, &bff[1], i - 1));
		}
		else if (!(fl & F_MINUS) && paddinng == ' ')
		{
			if (teamc)
				bff[--rang] = teamc;
			return (write(1, &bff[1], i - 1) + write(1, &bff[rang], lgth));
		}
		else if (!(fl & F_MINUS) && paddinng == '0')
		{
			if (teamc)
				bff[--paddinng_start] = teamc;
			return (write(1, &bff[paddinng_start], i - paddinng_start) +
				write(1, &bff[rang], lgth - (1 - paddinng_start)));
		}
	}
	if (teamc)
		bff[--rang] = teamc;
	return (write(1, &bff[rang], lgth));
}

/**
 * wrunsgnd - Writes an unsigned number
 * @maybenegative: Number rangicating if thenumberis negative
 * @rang: rangex at which the number starts in the bff
 * @bff: Array of chars
 * @fl: fl specifiers
 * @wd: wd specifier
 * @prs: prs specifier
 * @sz: sz specifier
 *
 * Return: Number of written chars.
 */
int wrunsgnd(int maybenegative, int rang,
	char bff[],
	int fl, int wd, int prs, int sz)
{
	/* The number is stored at the bufer's right and starts at position i */
	int lgth = buffy_sz - rang - 1, i = 0;
	char paddinng = ' ';

	UNUSED(maybenegative);
	UNUSED(sz);

	if (prs == 0 && rang == buffy_sz - 2 && bff[rang] == '0')
		return (0); /* printf(".0d", 0)  no char isprted*/

	if (prs > 0 && prs < lgth)
		paddinng = ' ';

	while (prs > lgth)
	{
		bff[--rang] = '0';
		lgth++;
	}

	if ((fl & F_ZERO) && !(fl & F_MINUS))
		paddinng = '0';

	if (wd > lgth)
	{
		for (i = 0; i < wd - lgth; i++)
			bff[i] = paddinng;

		bff[i] = '\0';

		if (fl & F_MINUS)
		{
			return (write(1, &bff[rang], lgth) + write(1, &bff[0], i));
		}
		else
		{
			return (write(1, &bff[0], i) + write(1, &bff[rang], lgth));
		}
	}

	return (write(1, &bff[rang], lgth));
}

/**
 * wrpointer - Write a memory address
 * @bff: Arrays of chars
 * @rang: rangex at which the number starts in the bff
 * @lgth: lgth of number
 * @wd: wd specifier
 * @fl: fl specifier
 * @paddinng: Char representing the paddinnging
 * @teamc: Char representing extra char
 * @paddinng_start: rangex at which paddinnging should start
 *
 * Return: Number of written chars.
 */
int wrpointer(char bff[], int rang, int lgth,
	int wd, int fl, char paddinng, char teamc, int paddinng_start)
{
	int i;

	if (wd > lgth)
	{
		for (i = 3; i < wd - lgth + 3; i++)
			bff[i] = paddinng;
		bff[i] = '\0';
		if (fl & F_MINUS && paddinng == ' ')
		{
			bff[--rang] = 'x';
			bff[--rang] = '0';
			if (teamc)
				bff[--rang] = teamc;
			return (write(1, &bff[rang], lgth) + write(1, &bff[3], i - 3));
		}
		else if (!(fl & F_MINUS) && paddinng == ' ')
		{
			bff[--rang] = 'x';
			bff[--rang] = '0';
			if (teamc)
				bff[--rang] = teamc;
			return (write(1, &bff[3], i - 3) + write(1, &bff[rang], lgth));
		}
		else if (!(fl & F_MINUS) && paddinng == '0')
		{
			if (teamc)
				bff[--paddinng_start] = teamc;
			bff[1] = '0';
			bff[2] = 'x';
			return (write(1, &bff[paddinng_start], i - paddinng_start) +
				write(1, &bff[rang], lgth - (1 - paddinng_start) - 2));
		}
	}
	bff[--rang] = 'x';
	bff[--rang] = '0';
	if (teamc)
		bff[--rang] = teamc;
	return (write(1, &bff[rang], buffy_sz - rang - 1));
}

