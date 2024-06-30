#include <setjmp.h>
#include <stdio.h>

jmp_buf jump;

/* Defining operations */
int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int div(int a, int b);

/* Array of pointers to function with signature `int func(int, int)` 
 * and assign the 4 declared operations to it
 * */
int (*oper[4])(int a, int b) = {add, sub, mult, div};

int main() {
	int i, result, a = 10, b = 5;
	// Determine size of input
	char input[100];

	if (setjmp(jump) != 0) {	/* Jump back here if invalid input */
		puts("You should insert a numeric value between 0 and 3!");
	}

	puts("Enter a value between 0 and 3:");

	// Read line of input
	fgets(input, sizeof(input), stdin);

	// Parse it and store in `i`
	sscanf_s(input, "%d", &i);

	if (i >= 0 && i <= 3) {
		result = oper[i](a, b);
	} else {
		longjmp(jump, 1);	/* If invalid input, jump back */
	}

	printf("THE RESULT OF 10 AND 5 IS\t%d\n", result);
}

int add(int a, int b) {
	return (a + b);
}

int sub(int a, int b) {
	return (a - b);
}

int mult(int a, int b) {
	return (a * b);
}

int div(int a, int b) {
	return (a / b);
}
