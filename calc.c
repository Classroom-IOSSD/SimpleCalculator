#include <stdio.h>
#include "operators.h"


int main(){
	FILE *fp = NULL;
	int operand1, operand2, line=0;
	char operator = ' ';
	double (*result)(int,int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = &add;
				break;
				case '-':
				result = &minus;
				break;
				case '*':
				result = &mul;
				break;
				case '/':
				result = &div;
				break;
			}		
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result(operand1,operand2));
		}
	}
	return 0;
}

