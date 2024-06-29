#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
	char buffer[BUFFER_SIZE]; /* <- Read Buffer */
	while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {	/* Writes stdin into buffer in a loop */
		printf("%s", buffer);	/* Writes the buffer into stdout */
	}
}
