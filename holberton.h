#ifndef _PRINTF_
#define _PRINTF_
#include <stdarg.h>

typedef struct op
{
	char *op;
	char *(*f)(va_list, int, char*);
}op_t;
int _printf(const char * const format, ...);
#endif /* _PRINTF_ */
