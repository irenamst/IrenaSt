#include<stdio.h>
#define MAXLINE 1000

int ReadMasiv(char line[], int maxline);
void squeeze(char s1[], char s2[]);

int main(void)
{
	char s1[MAXLINE];
	char s2[MAXLINE];

	ReadMasiv(s1, MAXLINE);

	ReadMasiv(s2, MAXLINE);

	squeeze(s1, s2);

	printf("%s", s1);
	getchar();
	return 0;
}

int ReadMasiv(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

void squeeze(char s1[], char s2[])
{
	int i;
	int j;
	int	k = 0;

	for (i = 0; s1[i] != '\0'; ++i)
	{
		for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; ++j)
			;
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}

	s1[k] = '\0';
}