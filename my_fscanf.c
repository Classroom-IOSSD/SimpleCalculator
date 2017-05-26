#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>

void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	char* cc;
	while (*format) {
	    if (*format == '%') {
		format++;
		int c,*_num;
		switch(*format) {
		case 'd' :
			while(isspace(c = getc(fp))) {}
			_num = va_arg(list, int*);
			unsigned int num = 0;
			while (isdigit(c)) {
				num = num * 10 + c - '0';
				c = getc(fp);
			}
			*_num = num;
			while(isspace(c = getc(fp))) {}
			ungetc(c,fp);
			break;
		case 'c' :
			cc = va_arg(list, char*);
			c = getc(fp);
			*cc =c;
			while(isspace(c = getc(fp))) {}
			ungetc(c,fp);
			break;
		}
 	}
	else 
		format++;
     } 	
	va_end(list);

}
