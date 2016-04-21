#include<stdio.h>
#define MAXVALUE 1000
int ReadArray(char s[], int maxline);
int htoi(char s[]);
int main(void) {
	char hex[MAXVALUE];
	ReadArray(hex, MAXVALUE);
	int dec;
	dec = htoi(hex);
	printf("The hexadecimal %s is equivalent to \n the decimal %d", hex, dec);
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
	//printf("%s\n",s);
	return i;
}
int htoi(char s[]) {
	int hexdigit, hexorNot;
	int i, n;
	i = 0;
	if (s[i] == '0') {
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	n = 0;
	hexorNot = 1;
	for (; hexorNot == 1; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else
			if (s[i] >= 'a' && s[i] <= 'f')
				hexdigit = s[i] - 'a' + 10;
			else
				if (s[i] >= 'A' && s[i] <= 'F')
					hexdigit = s[i] - 'A' + 10;
				else
					hexorNot = 0;
		//printf("%d\n", hexdigit);
		if (hexorNot == 1) {
			n = n * 16 + hexdigit;
			//printf("%d\n", n);
		}
	} return n;
}