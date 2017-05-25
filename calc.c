#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result = 0;
	int line=0;
	int (*sp1) (int,int)=add;
	int (*sp2) (int,int)=minus;
	int (*sp3) (int,int)=mul;
	double (*sp4) (int,int)=div;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = sp1(operand1, operand2);
				break;
				case '-':
				result = sp2(operand1, operand2);
				break;
				case '*':
				result = sp3(operand1, operand2);
				break;
				case '/':
				result = sp4(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

