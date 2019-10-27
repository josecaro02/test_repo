#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


char *print_s(va_list a, int i, char *buf)
{
	char *text;
	int j;

	j = 0;
	text = va_arg(a, char*);
	printf("caracte: %c", buf[i]);
	while (text[j] != '\0')
	{
		buf[i] = text[j];
		j++;
		i++;
	}
	buf[i] = '\0';
	printf("test: %s\n", buf);
	return (buf);
}

char *print_di(va_list a, int i, char *buf)
{
	char *num;

	num = va_arg(a, char*);
	buf[i] = num[0];
	return (num);

}


int _printf(const char * const format, ...)
{
	char *buf;
	char *test;
	/* char letter; */
	va_list valist;
	int i, k, j;
	op_t ops[] = {
		{"s", print_s},
		{"d", print_di},
		{"i", print_di},
		{NULL, NULL}
	};

	va_start(valist, format);
	i = 0;
	buf = malloc(1024);
	if (buf == NULL)
		return(0);
	while (format && format[i] != '\0')
	{
		k = 0;
		if (format[i] != '%')
			buf[i] = format[i];
		else
		{
			while (ops[k].op != NULL)
			{
				if (*ops[k].op == format[i + 1])
				{
					test = ops[k].f(valist, i + 1, buf);
					printf("%s", test);
				}
				k++;
			}
		}
		i++;
	}
	j = 0;
	/* while (buf[j] != '\0') */
	/* { */
	/* 	letter = buf[j]; */
	/* 	write(1, letter, 1); */
	/* } */
	printf("%s", buf);
	va_end(valist);
	free(buf);
	return (j);

}
