#include<stdio.h> 
int *setBit(int x, unsigned char p);

int main() {
	unsigned int x;
	unsigned int p;
	
	scanf_s("%x\n", &x);
	scanf_s("%u\n", &p);

	printf("%x\n", x);
	printf("%u\n", p);

	setBit(x,p);
	//printf("%x", x1);
	getchar();
	return 0;
}
int *setBit(int x, unsigned char p) {
	int* x1 = (int*)( x | (1 << p) );
return x1;
} 