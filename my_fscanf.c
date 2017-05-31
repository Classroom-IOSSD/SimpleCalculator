#include "my_fscanf.h"
#include <ctype.h>
#include <stdarg.h> 
#include <stdlib.h> 
#include <string.h> 

void my_fscanf(FILE *fp, const char* format, ...) {

	va_list list;
	va_start(list, format);
	int c;
	void* pVal;

	while (*format) {
		if (*format == '%') {
			format++;
			switch (*format) {
			case 'd':
				c = getc(fp);
				pVal = va_arg(list, int*);
				*(int*)pVal = 0;
				while (isdigit(c))
				{
					*(int*)pVal = *(int*)pVal * 10 + (c - '0');
					c = getc(fp);
				}
				ungetc(c, fp);
				break;
			case 'c':
				pVal = va_arg(list, char*);
				c = getc(fp);
				*(char*)pVal = c;
				break;
			case 's':
				pVal = va_arg(list, char*);
				((char*)pVal)[0] = 0;
				c = getc(fp);
				while (!isspace(c))
				{
					strncat((char*)pVal, &c , 1);
					c = getc(fp);
				}
				ungetc(c, fp);
				break;
			case 'f':{
					pVal = va_arg(list, float*);
					c = getc(fp);
					*(double*)pVal = 0;
					while (!isspace(c))
					{
						if (c == '.')
						{
							c = getc(fp);
							break;
						}
						*(double*)pVal = *(double*)pVal * 10 + (c - '0');
						c = getc(fp);
					}
					int n = 1;
					while (!isspace(c) && isdigit(c))
					{
						*(double*)pVal = *(double*)pVal  + (c - '0') *0.1 *n;
						c = getc(fp);
						n++;
					}
					ungetc(c, fp);
					break; 
				}
			}

		}
		else
			c = getc(fp);
		format++;
	}

	va_end(list);

}
