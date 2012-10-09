#include <stdio.h>

int main() {
	int cha, count;
	count = 0;

	while ((cha = getchar()) != EOF) {
		if (cha == ' ') {
			++count;
		}
	}
	printf("%d\n", count);

	return 0;
}
