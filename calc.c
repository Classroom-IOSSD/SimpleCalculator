#include <stdio.h>
#include "operators.h"

double cal (double oper1,double oper2, double (*func)(double,double))
{
	return func(oper1,oper2);
}
 

int main(){
	FILE *fp = NULL;
	double operand1, operand2;
	char operator = ' ';
	double result;
	int line = 0;
	double (*func)(double, double)=NULL;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
		
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%lf %c %lf",&operand1, &operator, &operand2);
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
			result = cal(operand1, operand2, func);		
			printf("%.0lf %c %.0lf = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

