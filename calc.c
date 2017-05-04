#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
		double (*funcOperator)(double ,double);
		for(int i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			if(feof(fp)) break;
			switch(operator) {
				case '+':
				funcOperator = &add;
				break;
				case '-':
				funcOperator = &minus;
				break;
				case '*':
				funcOperator = &mul;
				break;
				case '/':
				funcOperator = &div;
				break;
			}		
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, funcOperator(operand1,operand2));
		}
	}
	return 0;
}

