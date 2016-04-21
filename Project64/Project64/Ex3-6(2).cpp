//#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main() {
	int n;
	int width;
	char s[100];
	//scanf("%d",&n);
	//scanf("%d",&width);
	scanf_s("%d", &n);
	scanf_s("%d", &width);
	itoa(n,s,width);
	printf("%s\n",s);
	getchar();
	return 0;
}

void itoa(int n, char s[], int width) {
	int i;
	int sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n/=10)>0);
	if (sign < 0) {
		s[i++] = '-';
	}
	while (i < width)
		s[i++] = '*';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c;
	int i;
	int j;
	for(i=0, j=strlen(s)-1;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}