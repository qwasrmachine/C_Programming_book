#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main(void) {

	setlocale(LC_ALL, "en_US.utf8");

	/* Dissecting a line of data with sscanf_s()
	 * sscanf() is deprecated
	 * */

	char input[] = "25 54.32E-1 Thompson 56789 0123 56ß水";
	
	int i, j;
	float x, y;
	char str1[10], str2[4];
	wchar_t warr[2];	// A wide character takes more than 8 bits of space (normal character)

	/* Parse as follows:
	 * %i = integer
	 * %f = floating point variable
	 * %9s = string <= 9 non-whitespace chars
	 * %2i = 2 digit integer
	 * %*i = integer that isn't stored anywhere (* = assignment-surpressing character)
	 * ' ' = all the consecutive whitespace
	 * %3[0-9] = a string with up to 3 digits from 0 to 9
	 * %2lc = two wide (long) characters, using multibyte to wide conversion
	 * */

	// Returns the n. of fields
	int parsed = sscanf_s(input, "%i%f%9s%2d%f%*i %3[0-9]%2lc",
								&i, &x, str1, &j, &y, str2, warr);

	printf("Converted %i fields:\n"
			"i = %i\n"
			"x = %f\n"
			"str1 = %s\n"
			"j = %i\n"
			"y = %f\n"
			"str2 = %s\n",
			parsed, i , x, str1, j, y, str2);

	// wprintf supports wide characters
	// currently, it is printing the incorrect hex codes
	wprintf(L"widestring[0] = U+%x\n"
			L"widestring[1] = U+%x\n",
			warr[0], warr[1]);
}
