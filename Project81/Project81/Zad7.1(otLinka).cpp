#include <stdio.h>
#include <math.h>
#include <assert.h> 

const char menu[] = { "\nPlease enter:\n"
"\ta - to perform addition;\n"
"\tb - to perform subtraction;\n"
"\tc - to perform multiplication;\n"
"\td - to perform division;\n"
"\te - to perform exponentiation;\n"
"\tf - to quit;\n"
"\tChose option a - f: " };

char getMenuChoice(const char[], char, char);
double apply(char, double, double);
int mgetline(char s[], int lim);


int main()
{



	char operation;
	double op1;
	double op2;
	double result;

	do {
		operation = getMenuChoice(menu, 'a', 'f');

		if (operation == 'f') { break; }

		/*do {*/
		printf("Enter first value with digits!: ");
		scanf_s("%lf", &op1);
		/*if (op1 < -3.4e38 || op1 > 3.4e38) {
		printf("False\n");
		}
		else {
		printf("True\n");
		}*/
		/*} while ((op1 < -3.4e38 || op1 > 3.4e38));*/

		/*do {*/
		printf("Enter second value with digits!: ");
		scanf_s("%lf", &op2);
		/*if (op2 < -3.4e38 || op2 > 3.4e38) {
		printf("False\n");
		}
		else {
		printf("True\n");
		}*/
		//} while (/*(op2 < -3.4e38 || op2 > 3.4e38)*/);

		result = apply(operation, op1, op2);

		printf("\nThe result is %lf \n\n", result);

	} while (operation);

}

char getMenuChoice(const char menu[], char choice1, char choice2)
{
	char choice;

	do {
		printf("%s", menu);
		choice = getchar();
	} while (choice < choice1 || choice > choice2);

	return choice;
}

double apply(char operation, double op1, double op2)
{
	double result;
	switch (operation)
	{
	case 'a':
		result = op1 + op2; break;
	case 'b':
		result = op1 - op2; break;
	case 'c':
		result = op1 * op2; break;
	case 'd':
		result = op1 / op2; break;
	case 'e':
		result = pow(op1, op2);
	}
	return result;
}

int mgetline(char s[], int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	s[i] = '\0';
	return i;
}