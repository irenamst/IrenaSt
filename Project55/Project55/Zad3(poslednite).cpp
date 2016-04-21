#include<stdio.h>
int isPowerOfTwo(int x);
int count_ones(unsigned x);
int main() {
	unsigned x;
	unsigned yorn;
	scanf_s("%x", &x);
	int i;
	i = count_ones(x);
	yorn = isPowerOfTwo((int)i);
	printf("%d", yorn);
	getchar();
	return 0;
}
int isPowerOfTwo(int i) {
	if (i == 1)
		return 1;
	else
		return 0;
}
int count_ones(unsigned x) {
	int i;
	for (i = 0; x != 0; x &= (x - 1))
		i++;
	return i;
}