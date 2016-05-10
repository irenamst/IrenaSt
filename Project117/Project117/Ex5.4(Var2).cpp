#include<stdio.h>
#include<string.h>


int main() {
	char str1[50];
	char str2[50];
	int n;
	n = 10;
	

	int ret;
	memcpy(str1, "asdfghjklp", 10);
	memcpy(str2, "AxvgynjkmG", 10);
	ret = memcmp(str1,str2,n);
	if (ret>0) {
		printf("str2 is less than str1");
	}
	else if (ret < 0) {
		printf("str1 is less than str2");
	}
	else {
		printf("str1 is equal to str2");
	}
	getchar();
	return 0;
}




