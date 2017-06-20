#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE *fp, const char *format, ...) {
 va_list list;
 va_start(list, format);
 while(*format) {
 	if(*format == '%') {
 		int aa;
		format++;
 		switch(*format) {
 		case 'd':
 			while(isspace(aa=getc(fp))) {
			 }
			unsigned int num=0;
			while(isdigit(aa)) {
				num = num*10 + aa-'0';
				aa=getc(fp);
			}
			printf("%d",num);
			ungetc(aa,fp);
 		case 'c':
 			aa = getc(fp);
 			printf("%c",aa);
 		}
 	}
 }
 va_end(list);
}
