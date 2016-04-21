#include<stdio.h>
int Nula(unsigned x);
int Edinitsa(unsigned x);
int MostRigthByte(unsigned x);
int MostLeftByte(unsigned x);
int main() {
	unsigned x;
	scanf_s("%x", &x);
	int nul = Nula(x);
	printf("%x\n", nul);
	int edn = Edinitsa(x);
	printf("%x\n", edn);
	int mrb = MostRigthByte(x);
	printf("%x\n", mrb);
	int mlb = MostLeftByte(x);
	printf("%x\n", mlb);
	//printf("%d\n", Nula((unsigned)1010)); 
	//printf("%d\n", Edinitsa((unsigned)1010)); 
	//printf("%d\n", MostRigthByte((unsigned)1010)); 
	//printf("%d\n", MostLeftByte((unsigned)1010)); 
	getchar();
	return 0;
}
int Nula(unsigned x) {
	if (~x) {
		//printf("%x\n", ~x);
		return 1;
	}
	else {
		//printf("%x\n", ~x);
		return 0;
	}
}
int Edinitsa(unsigned x) {
	if (x) {
		//printf("%x\n", x); 
		return 1;
	}
	else {
		//printf("%x\n", x); 
		return 0;
	}
}
/*	int MostRigthByte(unsigned x) {
if (x << 24) return 1;
else
return 0;
}
*/

int MostRigthByte(unsigned x) {
	if (x & 0x000000FF) {
		//printf("%x\n", x & 0x000000FF);
		return 1;
	}
	else {
		//printf("%x\n", x & 0x000000FF);
		return 0;
	}
}
/*	int MostLeftByte(unsigned x) { if (x >> 24)
return 1;
else
return 0;
}
*/
int MostLeftByte(unsigned x) {
	if (x & 0xFF000000) {
		//printf("%x\n", x & 0xFF000000); 
		return 0;
	}
	else {
		//printf("%x\n", x & 0xFF000000); 
		return 1;
	}
}