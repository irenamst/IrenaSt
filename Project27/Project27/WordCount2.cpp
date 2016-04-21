#include <stdio.h>
int main(void){
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') 
			putchar('\n');
		else
			putchar(c);
	}
	getchar();
	return 0;
}