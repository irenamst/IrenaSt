#include<stdio.h>
#include<string.h>

int mgetline(char line[], int maxline);

int main() {
	char str1[50];
	char str2[50];
	int n;
	n = 50;
	mgetline(str1, 50);
	mgetline(str2, 50);

	int ret;
	ret = memcmp(str1, str2, n);
	if (ret>0) {
		printf("str2 is less than str1");
	}
	else if (ret < 0) {
		printf("str1 is less than str2");
	}
	else {
		printf("str1 is equal to str2");
	}
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