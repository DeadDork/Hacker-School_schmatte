#include <stdio.h>
// Maximum characters per line.
#define MAXIMUM 1000

// Ranges of ASCII values for charstream.
#define CHARSET_START '!' // ASCII value for space (32).
#define CHARSET_END '~' // ASCII value for ~ (126).

int main() {

	int c, i;
	char  line[MAXIMUM];

	int index = 0;
	int l_end = 1; // 0 == FALSE & 1 == TRUE.

	while ((c = getchar()) != EOF) {

		// if the line is at an end or exceeds the maximum length of the line.
		if (l_end == 0 && (c == '\n' || index >= MAXIMUM)) {

			// Use a for loop to get rid of any trailing white space.
			for (index; line[index] < CHARSET_START && line[index] > CHARSET_END; --index) {
				;
			}

			// Print the line.
			for (i = 0; i < index; ++i) {
				printf("%c", line[i]);
			}
			printf("\n");

			// Line end is set to TRUE.
			l_end = 1;

		}

		// Resets the character counter for that line.
		if (c == '\n') {
			index = 0;
		}

		// Sets the line end to false when the first character in the charstream after a newline is not a newline (e.g empty row).
		if (index == 0 && c != '\n') {
			l_end = 0;
		}

		// Assigns characters to the string array.
		if (l_end == 0) {
			line[index] = c;
			++index;
		}

	}

	return 0;

}
