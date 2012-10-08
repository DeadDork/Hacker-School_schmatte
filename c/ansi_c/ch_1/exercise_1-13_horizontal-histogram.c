#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
	int c, i, j, nc, state;
	int word_length[81];

	state = OUT;
	nc = 0;
	for (i = 0; i < 81; ++i) {
		word_length[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
			if (state == IN) {
				if (nc < 81) {
					++word_length[nc - 1]; // For words no longer than 80 chars.
				} else {
					++word_length[80]; // For words longer than 80 chars.
				}
			}
			state = OUT;
			nc = 0;
		} else {
			++nc;
			if (state == OUT) {
				state = IN;
			}
		}
	}

	for (i = 1; i < 81; ++i) {
		printf("Word length = %-10d: ", i);
		for (j = 0; j <= word_length[i - 1]; ++j) {
			printf("|");
		}
		printf("\n");
	}
	printf("Word length > 80        : ");
	for (j = 0; j <= word_length[80]; ++j) {
		printf("|");
	}
	printf("\n");

	return 0;
}
