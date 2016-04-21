#include<stdio.h>

/* print a histogram of the lengths of words in its input */

int main(void) {
	int c,i;
	int ncw = 0;
	while ((c = getchar()) != EOF) {
		
		if (c == ' ' || c == '\n' || c == '\t') {
				for (i = 0; i < ncw; i++) {
					putchar('*');
				}
				putchar('\n');
				ncw = 0;
		}
		else
		{
			ncw++;
		}
	}
	getchar();
	return 0;
}