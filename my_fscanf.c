
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>	
void my_fscanf(FILE *fp, const char *format, ... ) {
	va_list list;
	va_start(list, format);
	while(*format) {
		if(*format == '%') {
			format++;
			switch(*format)
			int* d;
			char* cc;
			int c;
			
			case 'd':
				while(isspace(c=getc(fp))){}
				d = va_arg(list, int);
				while (isdigit(c)) {
					num = num*10+c-'0';
					c = getc(fp);
				}
				*d = num;
				break;
			case 'c':
				cc = va_arg(list, char*);
				while (isspace(c = getc(fp))) {}
				cc = getc(fp);
				*cc = c;
				break;
		}
	}
	va_end(list);
}	
