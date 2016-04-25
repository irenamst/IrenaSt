#include<stdio.h>
#include<math.h>

#define Maximum 1000

void itoa(int n, char s[]);


int main(void)
{
	int n;
	char s[Maximum];
	scanf_s("%d", &n);
	itoa(n, s);           //kato prikljuchi s rekursiata idva tuk
	printf("%s", s);	  //print string s ot char
	getchar();
	return 0;
}

void itoa(int n, char s[])
{
	static int i;		//int i si zapazva stoinostta dokato se vurti rekursiata

	if (n / 10)          //if(m!=0),  n/10=m, m*10+p=n
		itoa(n / 10, s); //rekursia
	else
	{
		i = 0;			  //i=0;
		if (n < 0)		  //if (n=0)
			s[i++] = '-'; //s[i]='-'; 
						  //i++;
	}

	s[i++] = abs(n) % 10 + '0'; //s[i]=abs(i)%10 + '0';
								//i++;
	s[i] = '\0';

}