#include <stdio.h>
/*print Celsius-Fahrenheit  table
  for celsius=0,20,40,...,300 
  version*/
int main(void) {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; /* lower limit of temperature table*/
	upper = 300; /* upper limit of temperature table*/
	step = 20;

	celsius = lower;
	printf("Celsius-Fahrenheit Table\n");
	while (celsius <= upper) {
		fahr = (9.0 / 5.0)*celsius + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}