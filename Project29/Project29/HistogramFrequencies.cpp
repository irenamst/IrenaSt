#include<stdio.h>
int main(void) {
	int i, c, nwhite, nother;
	int num[52];

	nwhite = nother = 0;
	for (i = 0; i < 52; i++)
		num[i] = 0;
	while ( (c=getchar()) !=EOF) {
		if (c >= 'A' && c <= 'z')
			++num[c - 'A'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}
	printf("the frequencies of different characters = ");
	for (i = 0; i < 52; ++i)
		printf(" %d", num[i]);
	printf(",white space = %d, other = %d\n",nwhite,nother);
	//getchar();
	return 0;
}
