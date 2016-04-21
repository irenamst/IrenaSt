#include<stdio.h>
int ReadArray(char s[], int Maxline);
void copy(char s1[], char s2[]);
int main() {
	int len;
	int max;
	char sline[1000];
	char slongest[1000];
	max = 0;
	while ((len = ReadArray(sline, 1000))>0)
		if (len > max) {
			max = len;
			copy(slongest, sline);
		}
	if (max > 0)
		printf("%s", slongest);
	return 0;
}
int ReadArray(char s[], int lim) {
	int i, c;
	for (i = 0; i < lim - 1; ++i) {
		c = getchar();
		if (c == EOF)
			break;
		if (c == '\n')
			break;
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}
void copy(char s1[], char s2[]) {
	int i;
	i = 0;
	while ((s1[i] = s2[i]) != '\0')
		++i;
}