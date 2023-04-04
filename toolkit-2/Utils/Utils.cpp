#include "pch.h"
#include "Utils.h"


__declspec (dllexport) int Add(int num1, int num2) {

	return(num1 + num2);
}
__declspec (dllexport) int Multiple(int num1, int num2) {

	return (num1 * num2);
}
__declspec (dllexport) int Subtraction(int num1, int num2) {

	return (num1 - num2);
}

__declspec (dllexport) int Division(int num1, int num2) {

	if (num1 == 0 && num2 == 0)
		return 0;

	return (num1 / num2);
}