#include <stdio.h>

int main() {
	int c;

	// I thought that if there was more data after the newline, then the program will start reading again. Not the case.
	while ((c = getchar()) != '\n') {
		printf("%c", c);
	}

	return 0;
}
