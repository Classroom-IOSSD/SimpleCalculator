#include "operators.h"

float add(float op1, float op2) {
	return op1+op2;
}
float minus(float op1, float op2) {
	return op1-op2;
}
float mul(float op1, float op2) {
	return op1*op2;
}

float div(float op1, float op2) {
	if (op2 != 0) {
		return op1/op2;
	}
	else {
		return -1;
	}
}

