#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE* fp, const char* format, ...){
  va_list list;			//가변 인자 목록 포인터
  int dtemp=0;
  char temp;
  char ctemp= ' ';
  va_start(list, format);

  while(*format){
	if(*format == '%'){
	  format++;
	  switch(*format){
		case 'd':
			while(isspace(temp)){
			//empty
			}
			while(isdigit(temp)){
				dtemp = temp;
				temp = getc(fp);
			}
			dtemp = va_arg(list, int);
			dtemp = 0;
			format++;
			break;

		case 'c':
			while(isspace(temp)){
			//empty
			}
		  	while(isgraph(temp)){
				ctemp =temp;
				temp = getc(fp);
			}
			ctemp = va_arg(list, char);
			format++;
			break;
		default break;
		}
  }
  else if(isspace(*format)){
		format++;
	}
  }
  va_end(list);
}
			



