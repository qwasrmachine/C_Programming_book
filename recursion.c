#include <stdio.h>

int factorial(int num) {
	int ax;
	if (num > 1) {
		ax = factorial(num - 1);
		return num * ax;
	}
	return num;
}

int main() {
	int num = 5;
	printf("%i! = %i", num, factorial(num));
}
