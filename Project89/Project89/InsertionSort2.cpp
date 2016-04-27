#include<stdio.h>

void insertionSort(int *a,int n);
int main() {
	int arr[5], i;
	for (i = 0; i < 5; i++)
		scanf_s("%d",&arr[i]);
	insertionSort(arr,5);
	for  (i = 0; i < 5; i++)
		printf("%d\n",arr[i]);
	getchar();
	return 0;
}

void insertionSort(int *a, int n) {
	int k, j, temp;
	for (k=1;k<=n-1;k++) {
		temp = a[k];
		j = k - 1;
		while (temp < a[j] && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}