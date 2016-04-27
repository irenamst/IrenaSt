#include<stdio.h>
int main() {
	int array[100], n, c, position,d,swap;
	printf("Enter number of elements\n");
	scanf_s("%d",&n);
	printf("Enter %d integers numbers \n", n);
	for (c = 0;c<n; c++)
		scanf_s("%d",&array[c]);
		for (c=0;c<(n-1);c++) {
			position = c;
			for (d=c+1;d<n;d++) {
				if (array[position]>array[d])
					position = d;
			}
			if (position != 0) {
				swap = array[c];
				array[c] = array[position];
				array[position] = swap;
			}
		}
		printf("Sorted list in ascending order: \n");
		for (c = 0; c < n; c++) 
			printf("%d\n",array[c]);
		getchar();
		return 0;
}