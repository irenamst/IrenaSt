#include<stdio.h>
int checkOneBitSet(int i);
int countOnes(unsigned x);
int main() {
	unsigned x;
	scanf_s("%x", &x);
	char yorn;
	int i;
	i = countOnes(x);
	yorn = checkOneBitSet(i);
	printf("%d", yorn);
	getchar();
	return 0;
}
int checkOneBitSet(int i) {
	if (i == 1)   
		return 1;
	else
		return 0;
}
int countOnes(unsigned x) {
	int i;
	for (i = 0; x != 0; x &= (x - 1))
		i++;
	return i;
}