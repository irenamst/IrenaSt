#include<stdio.h> 
int *setBit(int x, unsigned char p);
//int mgetline(char s[], int lim);
int main() {
	unsigned int x;
	unsigned char p;
	int* x1;
	scanf_s("%x\n", &x);
	p = getchar();

	printf("%x\n", x);
	printf("%u\n", p);

	x1=setBit(x,p);
	printf("%x", x1);
	getchar();
	return 0;
}
int *setBit(int x, unsigned char p) {
	int* x1 = (int*)( x | (1 << p) );
return x1;
} 

//int mgetline(char s[], int lim) {
//	int i;
//	int c;
//	for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
//		s[i] = c;
//	if (c == '\n')
//		s[i++] = c;
//	s[i] = '\0';
//	return i;
//}