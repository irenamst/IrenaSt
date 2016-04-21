#include<stdio.h> 
//int setBit(int x, unsigned char p);

//raboti s 2 ichni chisla, no gi chete i izvejda 16 tichni -OK
int main() {
	unsigned int x;
	unsigned int p;
	int x1;
	scanf_s("%x\n", &x);
	scanf_s("%u\n", &p);

	x1 = x | (1 << p);
	printf("%x", x1);
	getchar();
	return 0;
}
/* int setBit(int x, unsigned char p) {
return x;
} */