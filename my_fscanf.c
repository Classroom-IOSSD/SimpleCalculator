// file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	int c;
	int *i;
	char *ch;
	
	while(*format) {
		if(*format == '%') {
			format++;
			switch(*format) {
			case 'd':
				i=va_arg(list,int*);
				while(isspace(c=getc(fp))){}
				*i=0;
				while(isdigit(c)){
					*i=(*i)*10+c-'0';
					c=getc(fp);
				}
				break;
			case 'c':
				ch=va_arg(list,char*);
				*ch=getc(fp);
				break;
			}
		}
		else{
			format++;
		}
	}
	va_end(list);
}
