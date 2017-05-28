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
				while(isspace(c=getc(fp))){} // skip leading white space
				unsigned int num = va_arg(list, int) = 0;
				while (isdigit(c)) {
					num = num * 10 + c - '0';
					c = getc(fp);
				}
				ungetc(c, fp);
				break;
			case 'c':
				while (isspace(c = getc(fp))) {} // skip leading white space
				c = getc(fp);
				break;

			}
		}
	}
	va_end(list);
}



