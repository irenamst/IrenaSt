#include<stdio.h>
int main(void) {
	int c;
	if ((c = getchar()) != EOF)
		putchar(c);
	return 0;
}