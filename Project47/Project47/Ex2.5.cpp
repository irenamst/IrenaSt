#include<stdio.h>
#define MAXVALUE 1000
int ReadArray(char masiv[], int maxline);
int any(char masiv1[], char masiv2[]);
int main(void) {
	char s1[MAXVALUE];
	char s2[MAXVALUE];
	int val;
	ReadArray(s1, MAXVALUE);
	ReadArray(s2, MAXVALUE);
	val = any(s1, s2);
	printf("%d", val);
	return 0;
}
int ReadArray(char s[], int lim) {
	int i, c;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}s
		[i] = '\0';
	return i;
}
int any(char s1[], char s2[]) {
	int i, j;
	int check_next_char;
	check_next_char = 1;
	for (i = 0; s1[i] != '\0' && (check_next_char);)
	{
		for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j)
			;
		if (s2[j] == '\0') {
			check_next_char = 1;
			i++;
		}
		else
			check_next_char = 0;
	} if (
		s1[i] == '\0')
		return -1;
	else
		return i;
}