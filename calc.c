#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	float operand1, operand2;
	char operator = ' ';
	float result, line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%f", &line);
	
		for(int i=1; i<line; i++) {
			fscanf(fp, "%f %c %f",&operand1, &operator, &operand2);
			
			float(*cal)(float, float);
			
			switch(operator) {
				case '+':
					cal = add;
				break;
				case '-':
					cal = minus;
				break;
				case '*':
					cal = mul;
				break;
				case '/':
					cal = div;
				break;
			}
			result = cal(operand1, operand2);		
			printf("%f %c %f = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

