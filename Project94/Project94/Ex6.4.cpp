#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>

#define MAXWORD 100
#define LIMIT 10

struct key {
	char *word;
	int count;
} keytab[LIMIT];

void print(int n);
int mgetword(char *, int);
int struct_cmp_by_count(const void *a, const void *b);

int main()
{
	int n; // number of words in the array
	char *word = (char*)malloc(sizeof(MAXWORD));
	int k, cond, found;
	char c;
	//////////////////////////////
	for (n = 0; n < LIMIT && ((c = mgetword(word, MAXWORD)) != EOF); n++)
	{
		found = -1;// the word is different from the array
				   //printf("%d", isalpha(word[0]));
		if (isalpha(word[0])) {

			for (k = 0; found == -1 && k < n; k++)//ako ne e namerena i ima oste elementi ot masiva pulni sdumi
			{
				cond = strcmp(keytab[k].word, word);
				//printf("cond= %d\n", cond);
				if (cond == 0) {
					found = k;
					break;
				}

			}

			//printf("found= %d\n", found);


			if (found<0) {
				//novata duma ne e sred purvite n dumi
				keytab[n].count = 1;
				keytab[n].word = (char*)malloc(sizeof(word));

				keytab[n].word = word;

				//printf("After copying %s\n\n", keytab[n].word);
			}
			else {
				//novata duma suvpada s nyakoya ot  purvite n dumi
				keytab[found].count++;
				//printf("keytab[found].count= %d\n", keytab[found].count);
				// na tazi s koyato suvpada se uvelichava broya
				if (n>0)n--; // za da nyama prazen element ot masiva
			}
		}
		word = (char*)malloc(sizeof(MAXWORD));
	}

	print(n);
	/////////////

	size_t structs_len = sizeof(keytab) / sizeof(struct key);

	/* sort array using qsort functions */
	qsort(&keytab, structs_len, sizeof(struct key*), struct_cmp_by_count);


	///////////////	

	getchar();
	return 0;

}

void print(int n) {
	int j;
	for (j = 0; j < n; j++)
		printf("%d %s\n", keytab[j].count, keytab[j].word);
}



/* getword: get next word or character from input */
int mgetword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

#define BUFSIZE  100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void)     /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push a character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters \n");
	else
		buf[bufp++] = c;
}

/////////////////////////////////////////////////////////
/* qsort struct comparision function (count int field) */
int struct_cmp_by_count(const void *a, const void *b)
{
	struct key *ia = (struct key *)a;
	struct key *ib = (struct key *)b;
	return (int)(ia->count - ib->count);
	/*return >0 if a->count > b->count*/
}