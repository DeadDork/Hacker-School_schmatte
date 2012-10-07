#include <stdio.h>

int main() {
	int a, b, c, d;

	a = '9';
	b = a - '0';
	c = a - 0;
	d = a - 10;

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("d = %d\n", d);

	return 0;
}
