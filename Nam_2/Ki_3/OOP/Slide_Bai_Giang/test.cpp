#include<stdio.h>

int main() {
	int a, b;
	printf("Vui long nhap lan luot a va b: ");
	scanf("%d%d", &a, &b);
	printf("a = %d; b = %d", a, b);
	
	int tong = a + b;
	printf("Tong bang: %d", tong);
	
	return 0;
}