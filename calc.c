#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int result, line, i = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			if(feof(fp) == 1)
				break;
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
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, (double)result);
		}
	}
	return 0;
}

