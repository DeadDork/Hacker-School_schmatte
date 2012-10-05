#include <stdio.h>

int main () {

	int b, c;

	b = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++b;
			if (b == 2) {
				c = 0;
				b = 0;
			}
		}
		putchar(c);
	}

	return 0;
}
