#include <stdio.h>

int main() {

	char a[] = {"hello"};
	char b[] = {"world"};

	printf("%10s,\n", a);
	printf("%-10s!\n", b);

	int c = '1';
	int d = '2';

	printf("[%10d]\n", c);
	printf("[%-10d]\n", d);
	
	return 0;
}
