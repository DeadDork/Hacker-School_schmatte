#include <stdio.h>

int main () {
	int c, b, t, nl;

	b = 0;
	t = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++b;
		}
		if (c == '\t') {
			++t;
		}
		if (c == '\n') {
			++nl;
		}
	}

	//Could have put all three in one printf, but didn't because that would be a huge pain to parse.
	printf("Blanks = %d\n", b);
	printf("Tabs = %d\n", t);
	printf("Newlines = %d\n", nl);
	
	return 0;
}
