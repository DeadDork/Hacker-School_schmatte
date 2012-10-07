#include <stdio.h>

int main() {
	int c;

	while((c = getchar()) != EOF) {
		if (c != '\n') {
			printf("char = %c\n", c);
			printf("int = %d\n\n", c);
		}
	}
	
	return 0;
}
