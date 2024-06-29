#include <setjmp.h>
#include <stdio.h>

jmp_buf jump;
int setjmp_jump;

void tryjump() {
	longjmp(jump, 3);
}

int main(void) {
	/* setjmp() creates a checkpoint and stores in jmp_buf when first called
	 * checkpoint can later be used by longjmp() call
	 * returns 0 if saved current context
	 * returns longjmp() int argument if the jump was performed
	 *
	 * the "checkpoint" is actualy the current execution context
	 * the execution context is composed by the state of the memory
	 * (both heap and stack), code, instruction pointer, registers, etc
	 * */
	setjmp_jump = setjmp(jump); // Jump back here
	if (setjmp_jump == 0) { // if saved execution context
		printf("execution context saved at setjmp(jump): %d\n", setjmp_jump);
		tryjump();
	} else { // if jump was performed
		printf("longjmp performed a jump and returned code %d\n", setjmp_jump);
	}
}
