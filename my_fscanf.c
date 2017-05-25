#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...){
	va_list list;
	int*d;
	char *dc;
	int c;
	va_start(list,format);
	while(*format){
		if(*format == '%'){
			format++;
			switch(*format){
			case 'd':
				d=va_arg(list,int*);
				while(isspace(c=getc(fp))){}
				unsigned int num =0;
				while(isdigit(c)){
					num=num*10+c-'0';
					c=getc(fp);
				}
				*d=num;
				break;
			case 'c':
				dc=va_arg(list,char*);
				c=getc(fp);
				*dc=c;
				break;
			case ' ':
				break;
			};
		}
		else
			format++;
	}
	va_end(list);
	printf("\n");
}
