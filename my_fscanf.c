#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE *fp, const char *format, ...)
{
	va_list list;
	va_start(list, format);
	int b;

	while(*format)
	{
		if(*format == '%')
		{
			format++;
			switch(*format)
			{
				case 'd':
					int* a = va_arg(list, int*);
					while(isspace(b = getc(fp))){}
					*a = 0;
					while (isdigit(b)){
						*a = *a * 10 + b - '0';
						b = getc(fp);
					}
					ungetc(c, fp);
					break;

				case 'c':
				
					char* c = va_arg(list, char*);
					b = getc(fp);
					*c = b;
					break;

				case 's':
					char* s = va_arg(list, char*);
					s[0] = 0;
					b = getc(fp);
					while(!isspace(b))
					{
						strncat(s, &b, 1);
						b = getc(fp);
					}
					ungetc(b, fp);
					break;

				case 'f':
					double* f = va_arg(list, float*);
					b = getc(fp);
					f = 0;
					while(!isspace(b)) 
					{
						if(b == '.')
						{
							b = getc(fp);
							break;
						}
						f = f * 10 + (b - '0');
						b = getc(fp);
					}
					int i = 1;
					while (!isspace(b) && isdigit(b))
					{
						f = f + (b - '0') *0.1 *i;
						b = getc(fp);
						n++;
					}
					ungetc(b, fp);
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
