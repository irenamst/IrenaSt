#include<stdio.h>
int main(void) {
	int c;
	c = getchar();
	if (c == EOF) {
		putchar(c);
	}
	return 0;
}
