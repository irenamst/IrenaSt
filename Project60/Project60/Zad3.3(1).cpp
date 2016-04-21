#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXVALUE 100

void expand(char s1[],char s2[]);

int main() {
	char s1[MAXVALUE];
	char s2[MAXVALUE];

	gets_s(s1);
	expand(s1,s2);
	printf("%s",s2);

	getchar();
	return 0;
}

void expand(char s1[], char s2[]) {
	int i, j;
	int d = strlen(s1);
	for (i = 0, j = 0; i <= d - 1; i++) {
		if (s1[i] != '-') {
			s2[j] = s1[i];
			while (isdigit(s1[i]) && (s1[i] <= s1[i + 2]) && (i + 1 < d))
				s2[j++] = s1[i]++;
			while (isalpha(s1[i]) && (s1[i] <= s1[i + 2]) && (i + 1 < d))
				s2[j++] = s1[i]++;
		}
	}
	s2[j] = '\0';
}