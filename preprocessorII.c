#include <string.h>
#include <stdio.h>

/* GENERIC
 *
 * PREPROCESSOR DIRECTIVES ARE EXTREMELY DANGEROUS, USE THE NATIVE C LANGUAGE CONSTRUCTS INSTEAD
 *
 * Same as preprocessor.c, but without knowing the members of the expanded sub-macros */

#define STRUCT_MEMBER(member, type, dummy) type member;

#define SERIALIZE_MEMBER(member, type, obj, buffer) \
	memcpy(buffer, &(obj->member), sizeof(obj->member)); \
	buffer += sizeof(obj->member);

#define DESERIALIZE_MEMBER(member, type, obj, buffer) \
	memcpy(&(obj->member), buffer, sizeof(obj->member)); \
	buffer += sizeof(obj->member);

#define FORMAT_(type) FORMAT_##type
#define FORMAT_int "%d"
#define FORMAT_double "%g"

/* `FORMAT_(type)` will be replaced with `FORMAT_int` or `FORMAT_double` */
#define PRINT_MEMBER(member, type, obj) \
	printf("%s: " FORMAT_(type) "\n", #member, obj->member);

/* StarStruct */

#define EXPAND_STAR(_, ...) \
	_(x, int, __VA_ARGS__) \
	_(y, int, __VA_ARGS__) \
	_(z, int, __VA_ARGS__) \
	_(radius, double, __VA_ARGS__)

typedef struct {
	EXPAND_STAR(STRUCT_MEMBER, )
} StarStruct;

void serialize_star(const StarStruct *const star, unsigned char *buffer) {
	EXPAND_STAR(SERIALIZE_MEMBER, star, buffer)
}

void deserialize_star(StarStruct *const star, const unsigned char *buffer) {
	EXPAND_STAR(DESERIALIZE_MEMBER, star, buffer)
}

void print_star(const StarStruct *const star) {
	EXPAND_STAR(PRINT_MEMBER, star)
}

