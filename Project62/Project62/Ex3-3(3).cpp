#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expand(char[], char[]);

int main()
{
	char str1[100];
	fgets(str1, 100, stdin);
	char str2[100];
	expand(str1, str2);
	printf("%s\n",str2);
	getchar();
	return 0;
}

void expand(char str1[], char str2[])
{

	int i;
	int j;
	int letter;

	i = 0;
	j = 0;

	while ((letter = str1[i++]) != '\0')
		if (str1[i] == '-' && str1[i + 1] >= letter)
		{
			i++;
			while (letter < str1[i])
				str2[j++] = letter++;
		}
		else
			str2[j++] = letter;

	str2[j] = '\0';
}