#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"
int main(){
	FILE *fp = NULL;
	int operand1, operand2,line=0;
	char operator = ' ';
	double result;
	double (*function_p) (int ,int );
	
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		my_fscanf(fp, "%d", &line);
		for(int i=0; i<line && !feof(fp); i++) {
			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				function_p = add;
				break;
				case '-':
				function_p = minus;
				break;
				case '*':
				function_p = mul;
				break;
				case '/':
				function_p = div;
				break;
			}
			result = function_p(operand1,operand2);
			printf("%d %c %d = %f\n",
				operand1, operator, operand2, result);
		}
	}
	return 0;
}
