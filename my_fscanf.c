// file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	int* parInt;
	char* parChar;
	while(*format) {
		if(*format == '%') {
			format++;
			switch(*format) {
				case 'c':
					parChar = va_arg(list,char*);
					printf("%d",*parChar);
					*parChar = getc(fp);
					break;
				case 'd':
					parInt = va_arg(list,int*);
					printf("%d",*parInt);
					while(isspace(*parInt = getc(fp))){}
					unsigned int num = 0;
					while(isdigit(*parInt)){
						num = num*10 + *parInt - '0';
						*parInt = getc(fp);
					}
					ungetc(*parInt,fp);
					break;
				}
			}
		}
	va_end(list);
}
