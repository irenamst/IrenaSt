#include<stdio.h>
int main(void)
{
	if (getchar() != EOF) 
		printf("1");
	else
		printf("0");
	getchar();
	return 0;
}