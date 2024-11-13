#include <stdio.h>

int main() {
	int a, b;
	printf("Nhap lan luot a va b: ");
	scanf("%d%d", &a, &b);
	int tong = a + b;
	if (tong == 0) {
		printf("Tong bang 0!\n");
	} else if ((tong % 2) == 0) {
		printf("Tong la mot so CHAN\n");
	} else {
		printf("Tong la mot so LE\n");
	}
}