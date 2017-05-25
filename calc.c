#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	double  operand1, operand2;
	char operator = ' ';
	double (* result)(double, double);
	double line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%lf", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp, "%lf %c %lf",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = &add;
				break;
				case '-':
				result = &minus;
				break;
				case '*':
				result = %mul;
				case '/':
				result = &div;
				break;
			}		
			printf("%.0lf %c %.0kf = %.6lf\n",
				 operand1, operator, operand2, result(operand1, operand2));
		}
	}
	return 0;
}

