#include <stdio.h>

#define MAXIMUM 1000 // Maximum characters per line.

// Ranges of ASCII values for charstream.
#define SPACE ' ' // ASCII value for space (32).
#define TILDE '~' // ASCII value for ~ (126).

int main() {
	int c, i, end;
	char line[MAXIMUM];

	int element = 0;
	int empty = 1; // 0 == FALSE & 1 == TRUE.

	while ((c = getchar()) != EOF) {
		if (element < MAXIMUM) {
			if (c != '\n') {
				line[element] = c;
			} else {
				for (i = 0; i <= element; ++i) {
					if (line[i] >= SPACE && line[i] <= TILDE) {
						empty = 0;
					}
					if (line[element] > SPACE && line[element] <= TILDE) {
						end = i;
					}
				}
				if (empty == 0) {
					for (i = 0; i <= end; ++i) {
						printf("%c", line[i]);
					}
				}
				printf("\n");
				element = 0;
				empty = 1;
			}
			++element;
		}
	}

	return 0;
}
