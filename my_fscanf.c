// file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	int* parInt;
	char* parChar;
	int c;
	while(*format) {
		if(*format == '%') {
			format++;
			switch(*format) {
				case 'c':
					parChar = va_arg(list,char*);
					*parChar = getc(fp);
					break;
				case 'd':
					parInt = va_arg(list,int*);
					while(isspace(c = getc(fp))){}
					*parInt=0;
					while(isdigit(c)){
						*parInt = *parInt*10 + c - '0';
						c = getc(fp);
					}
					break;
			}
		}else{
			format++;
		}
	}
	va_end(list);
}
