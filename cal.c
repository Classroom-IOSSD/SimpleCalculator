#include <stdio.h> 
#include <string.h> 
#include "my_fscanf.h" 

int main() {
	FILE* fp = fopen("points.txt", "r");     
	char type[10];     
	double x, y;     
	int line;
	int i;
	if (fp != NULL) 
	{ 
		my_fscanf(fp, "%d\r\n", &line);         
		for (i = 0; i < line; i++) { 
			my_fscanf(fp, "%s (%f,%f)\r\n", type, &x, &y); 
			if (strcmp(type, "point") == 0) 
			{
				printf("X: %f:, Y: %f\r\n", x, y); 
			} 
		} 
	}
	return 0;
}
