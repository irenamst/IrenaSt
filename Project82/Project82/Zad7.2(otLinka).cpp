#include <stdio.h>
#include <math.h>
#include <assert.h> 
#define NDEBUG 
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
	char name[20];
	printf("Enter your name: \n");
	mgetline(name, 20);

	int n;
	do {
		printf("Enter your age: \n");
		scanf_s("%d", &n);
	} while (n < 0 || n > 100);
	assert(n > 0 && n < 100);
	//char speciality[20];
	//printf("Enter your speciality: \n");
	//mgetline(speciality, 20);

	int assigN;
	do {
		printf("Enter your assigment N#: \n");
		scanf_s("%d", &assigN);
	} while (assigN <= 0 || assigN>1000000000);
	assert(assigN > 0 || assigN<1000000000);
	int course;
	do {
		printf("Enter your course \n");
		scanf_s("%d", &course);
	} while (course <= 0 || course >4);

	switch (course) {
	case 1: printf("You are %d st course\n", course); break;
	case 2: printf("You are %d nd course\n", course); break;
	case 3: printf("You are %d th course\n", course); break;
	case 4: printf("You are %d th course\n", course); break;
	}

	printf("Your name is %s\n", name);

	printf("You are %d years old\n", n);

	//printf("Your speciality is %s\n", speciality);

	printf("You have assigment N# %d\n", assigN);


	if (course == 2) {
		printf("You are %d nd course", course);
	}
	if (course == 3 || course == 4) {
		printf("You are %d th course", course);
	}



	char operation;
	double op1;
	double op2;
	double result1;



	operation = getMenuChoice(menu, 'a', 'f');
	do {


		printf("Enter first value with digits!: ");
		scanf_s("%lf", &op1);

		printf("Enter second value with digits!: ");
		scanf_s("%lf", &op2);

		result1 = apply(operation, op1, op2);

		printf("\nThe result is %lf \n", result1);
		if (operation == 'f') { break; }

	} while (operation);
	return 0;
}

char getMenuChoice(const char menu[], char choice1, char choice2)
{
	char choice;

	do {
		choice = getchar();
		printf("%s", menu);
	} while (choice<choice1 || choice >choice2);



	return choice;
}

double apply(char operation, double op1, double op2)
{
	double result;
	switch (operation)
	{
	case 'a':
		result = op1 + op2;
		break;
	case 'b':
		result = op1 - op2;
		break;
	case 'c':
		result = op1 * op2;
		break;
	case 'd':
		result = op1 / op2;
		break;
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
