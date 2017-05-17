#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE *fp, const char *format, ...)
{
	va_list list;
	va_start(list, format);
	int *a;
	int b;
	char *c;
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			switch(*format)
			{
				case 'd':
					a = va_arg(list, int*);
					while(isspace(b = getc(fp))){}
					unsigned int num = 0;
					while (isdigit(b)){
						num = num * 10 + b - '0';
						b = getc(fp);
					}
					*a = num;
					break;

				case 'c':
				
					c = va_arg(list, char*);
					b = getc(fp);
					*c = b;
					break;
				
				case ' ':
				
					break;		
			};
		}
		else
			format ++;
		
	}
	va_end(list);
}
