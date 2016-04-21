#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


char getMenuChoice(const char[], char, char);
double apply(char, double, double);
int mgetline(char s[], int lim);

int main()
{
	//printf("Irena \n");
	//printf("27 years old\n");
	printf("Enter your name: \n");
	char name[20];
	mgetline(name, 20);
	printf("Enter your age: \n");
	int n;
	scanf_s("%d",&n);
	fseek(stdin,0,SEEK_END);
	printf("Your name is %s\n",name);
	printf("You are %d years old", n);
	
	const char menu[] = { "\nPlease enter:\n"
		"\ta - to perform addition;\n"
		"\tb - to perform subtraction;\n"
		"\tc - to perform multiplication;\n"
		"\td - to perform division;\n"
		"\te - to perform exponentiation;\n"
		"\tf - to quit;\n"
		"\tChose option a - f: " };

	char operation = getMenuChoice(menu, 'a', 'f');
	double op1;
	double op2;
	double result;

	while (operation)
	{
		if (operation == 'f') { break; }
		//if (operation != 'a' && operation != 'b' && operation != 'c' && operation != 'd' && operation != 'e' && operation != 'f') { printf("Error!"); }

		/*int temp;
		if (temp == 1) {
			printf("Falsen\n");
		}*/
		
		do {
			printf("Enter first value with digits!: ");
			scanf("%lf", &op1);
			fseek(stdin, 0, SEEK_END);
			if (op1 < -3.4e38 || op1 > 3.4e38) {
				printf("False\n");
			}
			else {
				printf("True\n");
			}
		} while ((op1 < -3.4e38 || op1 > 3.4e38));

		do {
			printf("Enter second value with digits!: ");
			scanf("%lf", &op2);
			fseek(stdin, 0, SEEK_END);
			if (op2 < -3.4e38 || op2 > 3.4e38) {
				printf("False\n");
			}
			else {
				printf("True\n");
			}
		} while ((op2 < -3.4e38 || op2 > 3.4e38));

		result = apply(operation, op1, op2);

		printf("\nThe result is %lf \n\n", result);

		operation = getMenuChoice(menu, 'a', 'f');

	}
}

char getMenuChoice(const char menu[], char choice1, char choice2)
{
	char choice;

	do {
		printf("%s", menu);
		fseek(stdin, 0, SEEK_END);
		choice = getchar();
	} while (choice < choice1 || choice > choice2);

	return choice;
}

double apply(char operation, double op1, double op2)
{
	switch (operation)
	{
	case 'a':
		return op1 + op2;
	case 'b':
		return op1 - op2;
	case 'c':
		return op1 * op2;
	case 'd':
		return op1 / op2;
	case 'e':
		return pow(op1, op2);
	//default: printf("Error!");
	}
}

int mgetline(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	s[i] = '\0';
	return i;
}