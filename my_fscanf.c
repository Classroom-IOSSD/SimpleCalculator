#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h> 

void my_fscanf(FILE *fp, const char* format, ... ) {
	va_list list;
	va_start(list, format);
	while(*format) {
		if(*format == '%') {
			format++;
 
			switch(*format) {
			case 'd': { 
				c = getc( list );
				printf("%d", c);
				break; 
			}
			case 'c': {
				c = getc( list );
				printf("%c", c);
				break; 
			}		
			}

		}
		elseif(*format == ' ') {
			format++;
		}
		elseif(*format == '\n') {
			return 0;
		} 
	}
	va_end(list);
