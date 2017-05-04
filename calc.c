#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	float result;

	//using function_pointer
	int (*fp_add) (int, int);
	int (*fp_minus) (int, int);
	int (*fp_mul) (int, int);
	float (*fp_div) (int, int);
	fp_add = add;
	fp_minus = minus;
	fp_mul = mul;
	fp_div = div;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = fp_add(operand1, operand2);
				break;
				case '-':
				result = fp_minus(operand1, operand2);
				break;
				case '*':
				result = fp_mul(operand1, operand2);
				break;
				case '/':
				result = fp_div(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %f\n",operand1, operator, operand2, result);
		}
	}
	return 0;
}
