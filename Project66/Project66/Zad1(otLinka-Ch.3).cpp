#include <stdio.h>         // cin, cout, <<, >>
#include <string.h>           // string
#include <math.h>            // pow()

int main()
{	
	printf("\nPlease enter: \n");
	printf("\ta - to perform addition + \n");
	printf("\tb - to perform subtraction - \n");
	printf("\tc - to perform multiplication * \n");
	printf("\td - to perform division / \n");
	printf("\te - to perform exponentiation a^b \n");
	printf("\tf - to perform residue modulo a %% b \n");
	printf("--> ");
	int a;
	int b;
	char op;
	printf("Enter an operation :  ");
	op=getchar();
	printf("Enter two integers: \n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	
	

	switch (op)
	{
	case 'a': printf("%d + %d = %d\n", a, b, a + b);break;
	case 'b': printf("%d - %d = %d\n", a, b, a - b); break;
	case 'c': printf("%d * %d = %d\n", a, b, a * b);break;
	case 'd': printf("%d / %d = %d\n", a, b, a / b);break;
	case 'e': printf("%d ^ %d = %d\n", a, b, a ^ b);break;
	case 'f': printf("%d %% %d = %d\n", a, b, a % b); break;
	default: printf("Error!! \a \n");
	}
	getchar();
	return 0;
}