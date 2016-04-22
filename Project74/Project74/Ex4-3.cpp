#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s1[]);
void push(double f);
double pop(void);
double atof(char s2[]);


int main(void) {
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF)
	{
		switch (type) {
		case NUMBER:
				push(atof(s));
				break;
		case'+':
			push(pop()+pop());
			break;
		case'*':
			push(pop()*pop());
			break;
		case'-':
			op2 = pop();
			push(pop()-op2);
			break;
		case'/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error:zero divisor\n");
			break;
		case'%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error:zero divisor\n");
			break;
		case'\n':
			printf("\t%.8g\n",pop());
			break;
		default:
			printf("error: unknown command %s\n",s);
			break;
		}
	}
	getchar();
	return 0;
}
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:stack full, cant push %g\n",f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include<ctype.h>
int getch(void);
void ungetch(int c);

int getop(char s[]) {
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	if (c == '-')
		if (isdigit(c = getch()) || c=='.')
			s[++i] = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
		if (isdigit(c))
			while (isdigit(s[++i] = c = getch()))
				;
		if (c == '.')
			while (isdigit(s[++i] = c = getch()))
				;
		s[i] = '\0';
			if (c != EOF)
				ungetch(c);
			return NUMBER;
}

#define  BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}

double atof(char s[]) {
	double val, power1;
	int i, sign;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) 
		val = 10.0*val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power1 = 1.0; isdigit(s[i]); i++) {
		val = 10.0*val + (s[i]-'0');
		power1 *= 10.0;
	}
		
	
	return sign*val / power1;
}