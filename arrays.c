#include <stdio.h>
int main() {
	/* Two dimensional array with dynamic length rows */
	float linearA[30];		/* The rows are spanned through these 30 elements */
	float *A[6];			/* Array of 6 pointers to float, denoting 6 rows */

	/* Every array is spanned contiguously inside `linearA[]`
	 * but `A[]` gives the illusion that it is a matrix
	 * */

	A[0] = linearA;			/* A[0] points to idx 0 of linear[A]	n+1 - n		=	5 - 0	=	5 elements */
	A[1] = linearA + 5;		/* A[1] points to idx 5 of linear[A]	11 - 5		=	6 elements */
	A[2] = linearA + 11;	/* A[2] points to idx 11 of linear[A]	15 - 11		=	4 elements */
	A[3] = linearA + 15;	/* and so on... */
	A[4] = linearA + 21;
	A[5] = linearA + 25;

	/* Since Array[idx] is equal to *(Array + idx), there is no need to dereference A[3][2] */
	A[3][2] = 3.66;		/* linearA[17] = 3.66 */
	printf("A[3][2] = %f\nlinearA[17] = %f\n", A[3][2], linearA[17]);
}
