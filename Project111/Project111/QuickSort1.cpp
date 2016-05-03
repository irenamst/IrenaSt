#include <stdio.h>
#include <stdbool.h>

int a[] = { 84, 22, 159, 168, 171, 50, 181 ,200, 74, 28, 173, 65, 49, 10, 180, 5,
116, 52, 3, 47, 141, 11, 38, 167, 176,
109, 32, 178, 82, 59, 81, 150, 78, 41,
89, 27, 90, 83, 148, 95, 69, 170, 152,
43, 195, 113, 198, 45, 129, 132, 80, 92,
71, 4, 97, 126, 190, 39, 147, 119, 29, 193,
189, 179, 186, 37, 46, 138, 196, 161, 183,
117, 103, 112, 108, 58, 54, 162, 94, 199,
100, 131, 13, 151, 139, 135, 102, 191, 194,
105, 23, 165, 79, 185, 133, 68, 101, 55, 16,
128, 25, 118, 73, 24, 44, 86, 91, 169, 48, 96,
56, 18, 21, 15, 111, 77, 136, 63, 98, 104, 140,
40, 42, 177, 106, 175, 155, 51, 149, 53, 36, 122,
137, 34, 66, 156, 30, 114, 197, 163, 145, 17, 154,
158, 115, 88, 2, 19, 9, 64, 125, 1, 62, 187, 87, 134,
110, 142, 8, 160, 75, 57, 12, 76, 123, 172, 20, 120,
70, 35, 93, 14, 188, 143, 157, 130, 7, 72, 33, 164,
192, 124, 144, 60, 184, 67, 31, 99, 121, 182, 6, 85,
61, 107, 166, 174, 127, 146, 153, 26 };

void display();
int n;
void swap(int num1, int num2) {
	int temp = a[num1];
	a[num1] = a[num2];
	a[num2] = temp;
}

int partition(int left, int right, int pivot) {
	int leftPointer;
	int rightPointer;

	while (true) {
		for (leftPointer = left - 1; a[leftPointer] < pivot; leftPointer++)
			;

		for (rightPointer = right; rightPointer > 0 && a[--rightPointer] > pivot; )
			;


		if (leftPointer >= rightPointer) {
			break;
		}
		else {
			//printf(" item swapped :%d,%d\n",
			//	a[leftPointer], a[rightPointer]);
			swap(leftPointer, rightPointer);
		}

	}

	//	printf(" pivot swapped :%d,%d\n", a[leftPointer], a[right]);
	swap(leftPointer, right);
	//	printf("Updated Array: \n");
	//	display();
	return leftPointer;
}

void quickSort(int left, int right) {
	if (right - left <= 0) {
		return;
	}
	else {
		int pivot = a[right];
		int partitionPoint = partition(left, right, pivot);
		quickSort(left, partitionPoint - 1);
		quickSort(partitionPoint + 1, right);
	}
}

int main() {
	n = sizeof(a) / sizeof(a[0]);
	printf("Input Array: \n");
	display();
	quickSort(1, n);
	printf("Output Array: \n");
	display();
	getchar();
	return 0;
}

void display() {
	int i;
	for (i = 0; i <= n; i++)
		printf("%d\t ", a[i]);
	printf("\n");
}