#include<stdio.h>

//char clearBit(char x, unsigned char p);

int main() {
	int x;
	int p;
	scanf_s("%x\n", &x);
	scanf_s("%d\n", &p);
	int x1;
	x1 = x&(~(1 << p));
	printf("%x", x1);
	getchar();
	return 0;
}
/*char clearBit(char x, unsigned char p) {
x = x&(~(1<<p));
return x;
} */