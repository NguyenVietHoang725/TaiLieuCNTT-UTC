#include <stdio.h>
#include <stdbool.h>

bool binarySearch(int a[], int x, int left, int right) {
	if (left > right)
		return false;

	int mid = (left + right) / 2;

	// Base case:
	if (a[mid] == x)
		return true;

	// Recursive case:
	if (x > a[mid]) 
		return binarySearch(a, x, mid + 1, right);
	else 
		return binarySearch(a, x, left, mid - 1);
}

int main() {
	int a[9] = {2, 5, 7, 12, 17, 21, 22, 29, 55};
	printf("%d", binarySearch(a, 12, 0, 8));  // should print 1 (true)
	return 0;
}
