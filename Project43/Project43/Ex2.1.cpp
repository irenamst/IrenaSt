#include<stdio.h>
int main(void) {
	printf("Lower limit of signed char is %d\n", -(char)((unsigned char)~0 >> 1) - 1);
	printf("Upper limit of signed char is %d\n", (char)((unsigned char)~0 >> 1));
	printf("Lower limit of signed short is %d\n", -(short)((unsigned short)~0 >> 1) -
		1);
	printf("Upper limit of signed short is %d\n", (short)((unsigned short)~0 >> 1));
	printf("Lower limit of signed int is %6d\n", -(int)((unsigned int)~0 >> 1) - 1);
	printf("Upper limit of signed int is %6d\n", (int)((unsigned int)~0 >> 1));
	printf("Lower limit of signed long is %ul\n", -(long)((unsigned long)~0 >> 1) - 1);
	printf("Upper limit of signed long is %ul\n", (long)((unsigned long)~0 >> 1));
	int x = (int)((unsigned int)~0 >> 1);
	printf("Upper limit of unsigned char is %d\n", (unsigned char)~0);
	printf("Upper limit of unsigned short is %d\n", (unsigned short)~0);
	printf("Upper limit of unsigned int is 2 * %6d\n", x);
	printf("Upper limit of unsigned long is %ul\n", (unsigned long)~0);
	getchar();
	return 0;
}