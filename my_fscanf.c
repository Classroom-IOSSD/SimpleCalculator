// file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	int c,i;
	while(*format) {
		if(*format == '%') {
			format++;
			switch(*format) {
			case 'd':
				while(isspace(c=getc(fp))){}
				i=0;
				while(isdigit(fp)){
					i=i*10+c-'0';
					c=getc(fp);
				}
				i=va_arg(list,int);
				ungetc(c,fp);
			case 'c':
				c=getc(fp);
				c=va_arg(list,int);
			}
		}
	}
	va_end(list);
}
