#include<stdio.h>
/*count charaters in intput; first version*/
int main(void) {
	long nc;
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
	return 0;
}