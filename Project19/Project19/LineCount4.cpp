#include<stdio.h>
int main(void) {
	int c;
	while ((c=getchar())!=EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		}
	}
	return 0;
}