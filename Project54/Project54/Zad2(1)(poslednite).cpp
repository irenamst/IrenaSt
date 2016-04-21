#include<stdio.h>
int main() {
	unsigned x;
	int p;
	scanf_s("%x",&x);
	scanf_s("%d",&p);
	x = x&(~(1 << p));
	printf("%x", x);
	getchar();
	return 0;
}