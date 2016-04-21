#include<stdio.h>
int getl();
int main(void) {
	int len;
	int max;

	max = 0;
	while ((len = getl()) > 0)
		if (len > max)
			max = len;
	if (max > 0)
		printf("%d ", max);

	getchar();
	return 0;
}

int getl() {
	int nc = 0;
	int c;
	while ((c = getchar()) != EOF && c != '\n')
		++nc;
	return nc;
}