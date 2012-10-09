#include <stdio.h>

// CHAR_SET symbolizes the whole index of printable ASCII characters.
// '~' is an integer (i.e. ASCII decimal 126) & ' ' is an integer (i.e. ASCII decimal 32). Thus, '~' - ' ' = 92. Add 4 for '\n', '\r', '\t', and other.
#define CHAR_SET ('~' - (' ') + 4)

// These represent the array indexes for char_freq. N.B. Everything is shifted - 1 because the index starts at 0.
#define PRINT_CAR ('~' - ' ' - 1) // This actually only symbolizes the terminus of the printable character sequence. The range is from 0 - PRINT_CAR.
#define NEWLINE ('~' - ' ')
#define CAR_RET ('~' - ' ' + 1)
#define TAB ('~' - ' ' + 2)
#define OTHER ('~' - ' ' + 3)

int main() {
	int c, i, j, max_freq;
	int char_freq[CHAR_SET];

	max_freq = 0;
	for (i = 0; i < CHAR_SET; ++i) {
		char_freq[i] = 0;
	}

	// Get the character frequency for each character.
	while ((c = getchar()) != EOF) {
		if (c >= ' ' && c <= '~') {
			++char_freq[c - ' '];
		} else if (c == '\n') {
			++char_freq[NEWLINE];
		} else if (c == '\r') {
			++char_freq[CAR_RET];
		} else if (c == '\t') {
			++char_freq[TAB];
		} else {
			++char_freq[OTHER];
		}
	}

	// Get the maximum height of the histogram (for drawing a vertical histogram).
	for (i = 0; i < CHAR_SET; i++) {
		if (max_freq < char_freq[i]) {
			max_freq = char_freq[i];
		}
	}

	// Draw the histogram.
	for (i = max_freq; i >= 0; --i) {
		printf("%-10d", i); // Row number.
		for (j = 0; j < CHAR_SET; ++j) {
			if (char_freq[j] >= i) {
				printf("|");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	// Print ASCII values of above frequencies.
	printf("#.........");
	for (i = 0; i <= PRINT_CAR; i++) {
		printf("%c", i + ' ');
	}
	printf("NRTother\n"); // No good way to write "\n", etc.

	return 0;
}
