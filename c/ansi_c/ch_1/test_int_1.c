#include <stdio.h>

int main() {
	int c;

	while((c = getchar()) != EOF) {
		if (c != 10) {
			printf("char = %c\n", c);
			printf("int = %d\n\n", c);
		}
	}
	
	return 0;
}
