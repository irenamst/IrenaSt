#include<stdio.h>

int main() {
	int a;
	int b;
	printf("a=\n");
	scanf_s("%d",&a);
	printf("b=\n");
	scanf_s("%d",&b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a=%d, b=%d\n",a,b);
	getchar();
	return 0;
}