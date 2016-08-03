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
			}
		}
	}
	va_end(list);
}
