#include <string.h>

/*
 * PREPROCESSOR DIRECTIVES ARE EXTREMELY DANGEROUS, USE THE NATIVE C LANGUAGE CONSTRUCTS INSTEAD
 */

#define print_int(val) printf("%d", val)
#define print_double(val) printf("%g", val)
/* 1 Macro expands to 4 Macro calls */
#define EXPAND_STAR \
	EXPAND_STAR_MEMBER(x, int) \
	EXPAND_STAR_MEMBER(y, int) \
	EXPAND_STAR_MEMBER(z, int) \
	EXPAND_STAR_MEMBER(radius, double)

typedef struct {
	/* Preprocesses (generates) 4 new variables in this struct
	 * `EXPAND_STAR_MEMBER(member, type)` expands to `type member` */
	#define EXPAND_STAR_MEMBER(member, type) type member;
	EXPAND_STAR
	#undef EXPAND_STAR_MEMBER
} StarStruct;

void serialize_star(const StarStruct *const star, unsigned char *buffer) {
	/* Preprocesses (generates) serialization that copies the value of each
	 * struct member into the buffer and increases it's size */
	#define EXPAND_STAR_MEMBER(member, type) \
		memcpy(buffer, &(star->member), sizeof(star->member)); \
		buffer += sizeof(star->member);
	EXPAND_STAR
	#undef EXPAND_STAR_MEMBER
}

void deserialize_star(StarStruct *const star, const unsigned char *buffer) {
	/* Preprocesses (generates) deserialization that copies the value of each
	 * element from the buffer into the struct */
	#define EXPAND_STAR_MEMBER(member, type) \
		memcpy(&(star->member), buffer, sizeof(star->member)); \
		buffer += sizeof(star->member);
	EXPAND_STAR
	#undef EXPAND_STAR_MEMBER
}

void print_star(const StarStruct *const star) {
	/* Preprocesses (generates) code that prints to stdout each variable from struct */
	#define print_int(val) printf("%d", val)
	#define print_double(val) printf("%g", val)

	/* print_##type will be replaced with print_int or print_double */
	#define EXPAND_STAR_MEMBER(member, type) \
		printf("%s: ", #member); \
		print_##type(star->member); \
		printf('\n');
	EXPAND_STAR
	#undef EXPAND_STAR_MEMBER
}
