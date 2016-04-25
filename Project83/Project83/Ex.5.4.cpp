#include<stdio.h>
#define MAXLENGHT 1000

int mgetline(char line[], int maxline);
int strlength(char *t);
int strend(char *s, char *t);

int main() {
	char line1[MAXLENGHT];
	char line2[MAXLENGHT];
	mgetline(line1, MAXLENGHT);
	mgetline(line2, MAXLENGHT);
	int wherends;
	wherends = strend(line1, line2);
	printf("%d", wherends);
	getchar();
	return 0;
}

int mgetline(char s[], int lim) {
	int i;
	int c;
	for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strend(char *s, char *t) {
	int length;
	length = strlength(t);
	while (*s != '\0')
		++s;
	--s;
	while (*t != '\0')
		++t;
	--t;
	while (length > 0) {
		if (*t == *s) {
			--t;
			--s;
			--length;
		}
		else
			return 0;
	}
	if (length == 0)
		return 1;
}

int strlength(char *t) {
	char *p;
	p = t;
	while (*p != '\0')
		++p;
	return p - t;
}
