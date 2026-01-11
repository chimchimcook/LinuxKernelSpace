#include <stdio.h>
#include <stdint.h>

struct aaa {
	int a;
	int b;
	long c;
	double d;
};

#define CONTAINER_OF(p, type, member)                        \
	({                                                   \
		typeof(*p) *offset = &(((type *)0)->member); \
		(type *)((char *)p - (char *)offset);        \
	})

int main(void)
{
	struct aaa entry = {0};

	printf("entry: %p\n", &entry);

	int *p_a = &(entry.a);
	int *p_b = &(entry.b);
	long *p_c = &(entry.c);
	double *p_d = &(entry.d);

	printf("entry from a: %p\n", CONTAINER_OF(p_a, struct aaa, a));
	printf("entry from b: %p\n", CONTAINER_OF(p_b, struct aaa, b));
	printf("entry from c: %p\n", CONTAINER_OF(p_c, struct aaa, c));
	printf("entry from d: %p\n", CONTAINER_OF(p_d, struct aaa, d));
}
