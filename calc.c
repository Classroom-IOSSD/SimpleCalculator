#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int result, line, i = 0;
	double (*func)(int,int);
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			if(feof(fp) == 1)
				break;
			switch(operator) {
				case '+':
				func = add;
				break;
				case '-':
				func = minus;
				break;
				case '*':
				func = mul;
				break;
				case '/':
				func = div;
				break;
			}
			result = func(operand1, operand2);		
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, (double)result);
		}
	}
	return 0;
}

