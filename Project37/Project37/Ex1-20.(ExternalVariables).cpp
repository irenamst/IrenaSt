#include<stdio.h>

int main(void) {
	int nb, pos, c;
	nb = 0;
	pos = 1;

	while ((c=getchar())!=EOF) {
		if (c == '\t') {
			nb = 8 - ((pos-1)% 8 );
			while (nb > 0) {
				putchar('#');
				++pos;
				--nb;
			}
		}
		else if (c=='\n') {
			putchar(c);
			pos = 1;
		}
		else {
			putchar(c);
			++pos;
		}
	}
	return 0;
}