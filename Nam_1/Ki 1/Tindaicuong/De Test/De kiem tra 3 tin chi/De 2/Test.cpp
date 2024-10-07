// C program for Logical
// NOT Operator
#include <stdio.h>

// Driver code
int main()
{
	int a = 10, b = 20;

	if (!(a > 0 && b > 0)) {
		// condition returned true but
		// logical NOT operator changed
		// it to false
		printf("Both values are greater than 0\n");
	}
	else {
		printf("Both values are less than 0\n");
	}
	return 0;
}
