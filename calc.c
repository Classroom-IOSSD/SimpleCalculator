#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	float result, line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%f", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2); 
                    float (*cal)(float, float);
                    if (operator == '+')
                            cal = add;
                    else if (operator == '-')
                            cal = minus;
                    else if (operator == '*')
                            cal = mul;
                    else if (operator == '/')
                            cal = div;

                    result = cal(operand1, operand2);
                    printf("%d %c %d = %f\n", operand1, operator, operand2, result); 
            } 
				/*case '+':
				result = add(operand1, operand2);
				break;
				case '-':
				result = minus(operand1, operand2);
				break;
				case '*':
				result = mul(operand1, operand2);
				break;
				case '/':
				result = div(operand1, operand2);
				break;  */
					
		/*	printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result); */

	return 0;
}

}


