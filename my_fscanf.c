#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	while(*format) {
		if(*format == '%') {
			format++;
			switch(*format) {
			case 'd': {
				int c = getc(fp);
				int *pInt = va_arg(list, int*);
				*pInt = c - '0';
				break;
			}
			case 'f': {
				int c = getc(fp);
				while(isspace(c)) { c = getc(fp); }
				double *pDouble = va_arg(list, double*);
				double num = 0;
				while(isdigit(c)) {
					num = num*10 + c - '0';
					c = getc(fp);
				}
				*pDouble = num;
				break;
			}
			case 'c': {
				char c = getc(fp);				
				char *pChar = va_arg(list, char*);
				*pChar = c;
				break;
			}			
			}
		}
		else
			format++;
	}
	va_end(list);
}	
