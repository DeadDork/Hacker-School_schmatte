#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getliner(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	
	while ((len = getliner(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("Up to 1st 1,000 chars of longest line: %sTotal number of chars: %d\n", longest, max);
	}

	return 0;
}

/* getliner: read a line into s, return length */
int getliner(char s[], int lim) {
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 2) {
			s[i] = c;
		}
	}

	if (i < lim - 1 && c == '\n') {
		s[i] = c;
		s[++i] = '\0';
	} else {
		s[lim - 2] = '\n';
		s[lim - 1] = '\0';
	}

	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
