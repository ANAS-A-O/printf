#include "main.h"

/**
 * printability - Evaluates if a char is printable
 * @c: Char to be evaluatedz
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int printability(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexastuff - Append ascci in hexadecimal code to bff
 * @bff: Array of chars.
 * @i: rangex at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int hexastuff(char ascii_code, char bff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	bff[i++] = '\\';
	bff[i++] = 'x';

	bff[i++] = map_to[ascii_code / 16];
	bff[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * digitability - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int digitability(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_sz_number - Casts a number to the specified sz
 * @num: Number to be casted.
 * @sz: Number rangicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_sz_number(long int num, int sz)
{
	if (sz == S_LONG)
		return (num);
	else if (sz == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_sz_unsgnd - Casts a number to the specified sz
 * @num: Number to be casted
 * @sz: Number rangicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_sz_unsgnd(unsigned long int num, int sz)
{
	if (sz == S_LONG)
		return (num);
	else if (sz == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
