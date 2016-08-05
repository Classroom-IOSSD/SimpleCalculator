//file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	while (*format) {
		if (*format == '%') {
			format++;
			int c;
			switch (*format) {
			case 'd':
				while (isspace(c = getc(fp))) {} // skip leading white space
				unsigned int num = 0;
				int *d = va_arg(list, int*);
				while (isdigit(c)) {
					num = num * 10 + c - '0';
					c = getc(fp);
				}
				*d = num;
				ungetc(c, fp);
				break;
			case 'c':
				while (isspace(c = getc(fp))) {} // skip leading white space
				char *ch = va_arg(list, char*);
				//c = getc(fp);
				*ch = c;
				break;
			}
		}
		else
			format++;
	}
	va_end(list);
}



