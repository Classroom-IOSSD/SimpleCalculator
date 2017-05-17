#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result;
	int  line = 0;
	double (*addfp)(int, int)=add;
	double (*minusfp)(int, int)=minus;
	double (*mulfp)(int, int)=mul;
	double (*divfp)(double, double)=div;
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		my_fscanf(fp, "%d", &line);
	
		for(int i=1; i<line; i++) {
			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = addfp(operand1, operand2);
				break;
				case '-':
				result = minusfp(operand1, operand2);
				break;
				case '*':
				result = mulfp(operand1, operand2);
				break;
				case '/':
				result = divfp(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

