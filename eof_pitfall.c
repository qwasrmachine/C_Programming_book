#include <stdio.h>
int main() {
	int c;

	/* When compared to EOF or -1:
	 *		Loops forever, windows probably sends characters such as \n and \r that blocks the stdin from reaching EOF
	 * When compared to '\n':
	 *		It only executes once, maybe same reason of EOF pitfall
	 *
	 *		NEVER USER TYPE char WHEN TESTING AGAINST EOF
	 *
	 * */
	while ((c = getc(stdin)) != EOF) {
		putc(c, stdout);
	}
}
