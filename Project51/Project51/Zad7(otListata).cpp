#include<stdio.h>
//unsigned getbits(unsigned x, int p, int n);
//void rotate_left(unsigned x, int n);
int main() {
	unsigned x;
	unsigned x1;
	unsigned x2;
	int p;
	int n;
	scanf_s("%x\n", &x);
	//printf_s("%x\n",x);
	scanf_s("%d\n", &p);
	scanf_s("%d\n", &n);
	//x1 = getbits((unsigned)x, (int)p, (int)n);
	//rotate_left((unsigned)x1,(int) n); 
	x1 = (x >> (p + 1 - n))&(~(~0 << n));
	x2 = (x << n) | x1;
	printf_s("%x", (unsigned int)x2);
	getchar();
	return 0;
}