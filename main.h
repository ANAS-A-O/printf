#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define buffy_sz 1024

/* fl */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* szS */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int hdl_print(const char *fmt, int *i,
va_list list, char bff[], int fl, int wd, int prs, int sz);

/********* FUNCTIONS *********/
/* Funtions to print chars and strings */
int printerchar(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);
int printerstring(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);
int printerpercent(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);

/* Functions to print numbers */
int printerint(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);
int printerbinary(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);
int printerunsigned(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);
int printeroctal(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);
int printerhexadecimal(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);
int printerhexa_upper(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);

int printerhexa(va_list typ, char map_to[],
char bff[], int fl, char flag_ch, int wd, int prs, int sz);

/* Function to print non printable characters */
int printernon_printable(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);

/* Funcion to print memory address */
int printerpointer(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);


/* Funciotns to hdl other specifiers */
int teampr(const char *format, int *i, va_list list);
int teamsz(const char *format, int *i);
int teamfl(const char *format, int *i);
int teamwd(const char *format, int *i, va_list list);


/*Function to print string in reverse*/
int printerreverse(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);

/*Function to print a string in rot 13*/
int printerrot13string(va_list typ, char bff[],
	int fl, int wd, int prs, int sz);

/* wd hdlr */
int hdl_wrchar(char c, char bff[],
	int fl, int wd, int prs, int sz);
int wrnumber(int positivity, int rang, char bff[],
	int fl, int wd, int prs, int sz);
int wrnum(int rang, char bff[], int fl, int wd, int prs,
	int lgth, char paddinng, char teamc);
int wrpointer(char bff[], int rang, int lgth,
	int wd, int fl, char paddinng, char teamc, int paddinng_start);

int wrunsgnd(int maybenegative, int rang,
char bff[],
	int fl, int wd, int prs, int sz);

/********* UTILS *********/
int printability(char);
int hexastuff(char, char[], int);
int digitability(char);

long int convert_sz_number(long int num, int sz);
long int convert_sz_unsgnd(unsigned long int num, int sz);

#endif /* MAIN_H */

