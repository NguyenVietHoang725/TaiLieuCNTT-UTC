#include <stdio.h>

int tong (int n) {
	if (n == 1) return 1;
	else return n + tong(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	
	printf("Tong bang %d", tong(n));
}