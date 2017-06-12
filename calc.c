#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

double calc(double op1, double op2, char op) {
	double (*func)(double, double);
	double ans;
	switch(op) {
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
	ans = func(op1, op2);
	return ans;
}

int main(){
	FILE *fp = NULL;
	double operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		my_fscanf(fp, "%d", &line);
		for(int i=1; i<line; i++) {
			my_fscanf(fp, "%f %c %f",&operand1, &operator, &operand2);
			result = calc(operand1, operand2, operator);
			printf("%f %c %f = %f\n", operand1, operator, operand2, result);
		}
	}
	return 0;
}

