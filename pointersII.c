/* Typedef `FuncType` as a pointer to a function with the signature `(int, void *)`
 * the `void *` pointer implements a callback
 *
 * This is a fucking mess...
 * */
#include <stdio.h>
typedef int (*FuncType)(int, void *);

#define LARGEST 100

int DoFoo(int aVar, FuncType aFunc, void *dataPtr) {

	int rv = 0;

	/* This is really calling GetColorSpec(41, {15, "Who the heck is Willis?"}) */
	if (aVar < LARGEST) {
		rv = (*aFunc)(aVar, dataPtr);		/* This invokes the function `aFunc` through function pointer (deprecated) */
	} else {
		rv = aFunc(aVar, dataPtr);			/* This also invokes the function `aFunc` through a function pointer (modern) */
	}
	
	return rv;
}

typedef struct {
	int colorSpec;
	char *phrase;
} DataINeed;

int GetColorSpec(int num, void *bar) {
	DataINeed *myData = bar;			/* Cast `void *` to `DataINeed *` */
	return myData->colorSpec;
}

int main(){
	static DataINeed sillyStuff = { 15, "Who the heck is Willis?" };
	int printThis = DoFoo(41, &GetColorSpec, &sillyStuff);
	printf("GetColorSpec returned %d\n", printThis);
}

