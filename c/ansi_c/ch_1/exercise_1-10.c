#include <stdio.h>

int main () {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t");
			c = 0;
		}
		if (c == '\b') {
			printf("\\b");
			c = 0;
		}
		if (c == '\\') {
			printf("\\\\");
			c = 0;
		}
		putchar(c);
	}

	return 0;
}
