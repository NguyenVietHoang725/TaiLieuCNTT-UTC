#include <stdio.h>
int main() {
	int n = 36;
	for (int i = 2; i*i <= n; i++) {
		while (n % i == 0) {
			printf("%d ", i);
			n /= i;
		}
	}
	if (n > 1) printf("%d", n);
}