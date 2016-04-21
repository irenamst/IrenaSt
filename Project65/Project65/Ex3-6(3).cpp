#include<stdio.h>
#include<string.h>
#define MAXLIMIT 100

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
	int number;
	int width;
	scanf_s("%d\n",&number);
	scanf_s("%d\n",&width);
	char str[MAXLIMIT];
	itoa(number,str,width);
	printf("%s",str);
	getchar();
	return 0;
}

void itoa(int n, char s[], int w) {
	int i;
	int sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = (n % 10) + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	while (i < w)
		s[i++] = ' ';
	s[i] = '\0';
	//s[w] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int i, j, c;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}