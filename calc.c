#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	double operand1, operand2, result=0;
	char operator = ' ';
	int  line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp, "%lf %c %lf",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = add(operand1, operand2);
				break;
				case '-':
				result = minus(operand1, operand2);
				break;
				case '*':
				result = mul(operand1, operand2);
				break;
				case '/':
				result = div(operand1, operand2);
				break;
			}		
			printf("%.lf %c %.lf = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

