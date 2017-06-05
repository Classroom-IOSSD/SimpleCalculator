//file: my_fscanf.c
#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	while (*format) {
		if (*format == '%') {
			format++;
			int c;
			switch (*format) {
			case 'd':
				while (isspace(c = getc(fp))) {} // skip leading white space
				unsigned int num = 0;
				int *d = va_arg(list, int*);
				while (isdigit(c)) {
					num = num * 10 + c - '0';
					c = getc(fp);
				}
				*d = num;
				ungetc(c, fp);
				break;
			case 'c':
				while (isspace(c = getc(fp))) {} // skip leading white space
				char* ch = va_arg(list, char*);
				*ch = c;
				break;
			case 'f':
				//double atof(const cahr*)
				while (isspace(c = getc(fp))) {}
				double* floating_point = va_arg(list, double*);
				double front_num = 0, back_num = 0;
				double k = 0.1; // k는 소수점 자리수를 뒤로 넘겨주는 변수
				while (isdigit(c)) {
					front_num = front_num * 10 + c - '0';
					c = getc(fp);
				}
				if (c == '.') {
					c = getc(fp);
				}
				while (isdigit(c)) {
					back_num = back_num + (c - '0')*k;
					c = getc(fp);
					k = k*0.1;
				}
				*floating_point = front_num + back_num;
				ungetc(c, fp);
				format++;
				break;
			case 's':
				//strcpy(복사받을 변수명, 복사할 변수명)
				while (isspace(c = getc(fp))) {}
				char* str = va_arg(list, char*);
				int count = 1;
				str[0] = c;
				while (!isspace(c = getc(fp)) && !isdigit(c)) {
					str[count] = c;
					count++;
				}
				str[count] = '\0';
				ungetc(c, fp);
				format++;
				break;
			}
		}
		else {
			//compar a character with format
			int c = getc(fp);
			format++;
		}

			
	}
	va_end(list);
}

