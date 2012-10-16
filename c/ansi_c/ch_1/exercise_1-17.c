#include <stdio.h>

#define MINIMUM 80
#define MAXIMUM 1000

int main() {
	int c, i, count;

	char line[MAXIMUM];

	count = 0;

	while ((c = getchar()) != EOF && count < MAXIMUM) {
		if (c != '\n') {
			line[count] = c;
			++count;
		} else {
			if (count >= MINIMUM) {
				for (i = 0; i < count; ++i) {
					printf("%c", line[i]);
				}
				printf("\n");
			}
			count = 0;
		}
	}

	return 0;
}
