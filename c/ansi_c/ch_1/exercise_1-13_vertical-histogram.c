#include <stdio.h>

#define IN 1
#define OUT 0
#define LENGTH 81

int main() {
	int c, i, j, max_height, state, nc;
	int word_frequency[LENGTH];

	state = OUT;
	max_height = nc = 0;
	for (i = 0; i < LENGTH; ++i) {
		word_frequency[i] = 0;
	}
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
			if (state == IN) {
				if (nc < LENGTH) {
					++word_frequency[nc - 1];
				} else {
					++word_frequency[LENGTH];
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

	for (i = 0; i < LENGTH; ++i) {
		if (max_height < word_frequency[i]) {
			max_height = word_frequency[i];
		}
	}

	for (i = max_height; i >= -1; --i) {
		for (j = 0; j <= LENGTH; ++j) {
			if (word_frequency[j] > i) {
				printf("-");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
