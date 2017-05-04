#include <stdio.h>
#include "operators.h"
double add (int a, int b){
		return a+b
}
double minus (int a, int b){
		return a-b;
}
double mul(int a,int b){
		return a*b;
}
double div(int a, int b){
		return a/b;
}
int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int result
	double line = 0;
	double (*fp) (int, int);
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=1; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				fp = add;
				result=fp(operand1, operand2);
				break;
				case '-':
				fp = minus;
				result=fp(operand1, operand2);
				break;
				case '*':
				fp = mul;
				result=fp(operand1, operand2);
				break;
				case '/':
				fp = div;
				result=fp(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

