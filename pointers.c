#include <stdio.h>
struct MyStruct {
	int m_aNumber;
	float num2;
};

struct MyStruct *SillyFunction(int b) {
	/* When returning a pointer, the memory it points to can't get cleaned when the scope ends
	 * otherwise the pointer will become invalid.
	 * So the memory the pointer will point to should be static or dynamically allocated with malloc.
	 * */
	static struct MyStruct val1, val2, val3, val4;		/* Outlives function scope */
	struct MyStruct *myReturn;

	if (b == 1) myReturn = &val1;
	else if (b == 2) myReturn = &val2;
	else if (b == 3) myReturn = &val3;
	else myReturn = &val4;

	return myReturn;
};

int main() {
	struct MyStruct *strPtr;
	int *c, *d, j;

	c = &j;
	d = c;		/* Now `d` and `c` points to `j` */

	strPtr = SillyFunction(3);		/* `strPtr` points to  val3 */

	(*strPtr).m_aNumber = 3;	/* Dereferences `strPtr`, and access the property `m_aNumber` from the struct */
	strPtr->num2 = 44.3;		/* The arrow operator simplifies dereferencing */
	*d = strPtr->m_aNumber;		/* j = 3 */

	printf("The number is %d", j);
}

