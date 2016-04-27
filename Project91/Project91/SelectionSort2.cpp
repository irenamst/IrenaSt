#include<stdio.h>

void selectionSort(int *a,int n);

int main() {
	int arr[5];
	int i;
	printf("Enter 5 integer numbers\n");
	for (i = 0; i < 5; i++)
		scanf_s("%d", &arr[i]);
	selectionSort(arr,5);
	for (i = 0; i < 5; i++)
		printf("%d\n", arr[i]);
	getchar();
	return 0;
}

void selectionSort(int *a, int n) {
	int k, j, pos, small, temp;
	for (k = 1;k<=n-1;k++) {
		small = a[k-1];
		pos = k - 1;
		for (j = k; j <= n - 1; j++) {
			if (a[j] < small) {
				small = a[j];
				pos = j;
			}
		}
		if (pos != k - 1) {
			temp = a[k - 1];
			a[k - 1] = a[pos];
			a[pos] = temp;
		}
	}
}