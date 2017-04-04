#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	float result = 0;
	int line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			if (operator == ' ') {
				return 0;
			}
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
			printf("%d %c %d = %d\n",
				 operand1, operator, operand2, result);
			operand1 = 0;
			operator = ' ';
			operand2 = 0;
			result = 0;
		}
	}
	return 0;
}

