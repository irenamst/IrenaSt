#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1000
int mgetline(char line[], int maxline);
void mstrncpy(char *s, char *t, int n);
int strlength(char *s);
void mstrncat(char *s1, char *s2, char *t, int n);
int mstrncmp(char *s, char *t, int n);

int main() {
	char s[] = "ABCDEF";
	char t[] = "GHIJ";
	//int n;			  
	//n=4
	//scanf_s("%d",&n);
	//mgetline(s, MAXLINE);
	//mgetline(t, MAXLINE);
	mstrncpy(t, s, 4);
	printf("%s\n", t);

	char s1[] = "ABCD";
	char t1[] = "EFGHIJ";
	//mgetline(s1, MAXLINE);
	//mgetline(t1, MAXLINE);
	char *d;

	/* We store the result in a new string d */

	if ((d = (char *)malloc(sizeof(char) * (strlen(s1) + 4 + 1))) == NULL) {
		printf("unable to allocate memory \n");
		return -1;
	}

	mstrncat(s1, t1, d, 4);
	printf("%s\n", d);     /* ABCDEFGH */

	free(d);

	char s2[] = "ABCDEF";
	char t2[] = "ABC";
	//int m; 
	//m=3
	//scanf_s("%d", &m);
	//mgetline(s2, MAXLINE);
	//mgetline(t2, MAXLINE);
	int result;
	result = mstrncmp(s2, t2, 3);

	printf("%d\n", result);
	getchar();
	return 0;
}

int mgetline(char s[], int lim) {
	int i, c;
	for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

void mstrncpy(char *s, char *t, int n) {
	while (*t != '\0' && n>0) {
		n--;
		*s = *t;
		s++;
		t++;
	}
	int m = strlength(s) - n;
	while (m>0) {
		m--;
		s++;
	}
	*s = '\0';
}

int strlength(char *s) {
	char *p;
	p = s;
	while (*s != '\0')
		s++;
	return s - p;
}

void mstrncat(char *s1, char *s2, char *t, int n) {
	while (*s1 != '\0') {
		*t = *s1;
		t++;
		s1++;
	}
	while (n > 0) {
		n--;
		*t = *s2;
		t++;
		s2++;
	}
	*t = '\0';
}

int mstrncmp(char *s, char *t, int n) {
	for (; *s == *t; s++, t++) {
		n--;
		if (*s == '\0' || n > 0)
			return 0;
	}
	return *s - *t;
}