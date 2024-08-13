#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

struct Address
{
	int rows;
	int cols;
};

int** insertMatrix(int** a, int* rows, int* cols)
{
	// Enter value of the row
	re1:
	printf("Enter value of the row: ");
	scanf("%d", rows);
	if (*rows <= 0)
	{
		printf("The minimum value of rows is 1. Please enter again!\n");
		goto re1;
	}
	// Enter value of the col
	re2:
	printf("Enter value of the col: ");
	scanf("%d", cols);
	if (*cols <= 0)
	{
		printf("The minimum value of cols is 1. Please enter again!\n");
		goto re2;
	}
	// 
	a = (int**) malloc((*rows + 1) * sizeof(int*));
	for (int i = 0; i < *rows; i++)
	{
		a[i] = (int*) malloc((*cols + 1) * sizeof(int));
	}
	
	printf("Enter the values of the elements:\n");
	for (int i = 0; i < *rows; i++)
		for (int j = 0; j < *cols; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	return a;
}

void displayMatrix(int** a, int rows, int cols)
{
	printf("The matrix is:\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}

int findMaxElement(int** a, int rows, int cols)
{
	int max = INT_MIN;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (max < a[i][j]) max = a[i][j];
		}
	return max;

}

int findMaxX(int** a, int rows, int cols, int *x)
{
	printf("Enter the value of element x: ");
	scanf("%d", x);
	int max = INT_MIN;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (max < a[i][j] && a[i][j] < *x) max = a[i][j];
		}
	return max;
}

int findMinElement(int** a, int rows, int cols)
{
	int min = INT_MAX;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (min > a[i][j]) min = a[i][j];
		}
	return min;
}

int findMinX(int** a, int rows, int cols, int *x)
{
	printf("Enter the value of element x: ");
	scanf("%d", x);
	int min = INT_MAX;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
			{
				if (min > a[i][j] && a[i][j] > *x) min = a[i][j];
			}
		return min;
}

Address* saveAddressElement(int** a, int rows, int cols, int *n, int x)
{
	Address* sA;
	sA = (Address*) malloc(rows * cols * sizeof(Address));
	*n = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (a[i][j] == x)
			{
				sA[*n].rows = i;
				sA[*n].cols = j;
				*n += 1;
			}
		}
	}
	return sA;
}

void printAddressElement(Address* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("[%d][%d], ", a[i].rows, a[i].cols);
		else printf("[%d][%d].\n", a[i].rows, a[i].cols);
	}
}

int chooseValue(int *choose)
{
	printf("Choose comparison:\n");
	printf("Larger (1)\n");
	printf("Equal (0)\n");
	printf("Smaller (-1)\n");
	re:
	printf("Enter the value: ");
	scanf("%d", choose);
	if (*choose != 0 && *choose != -1 && *choose != 1)
	{
		printf("The input value is not satisfied. Please enter again!\n");
		goto re;
	}
	return *choose;
}
int countElement(int rows, int cols, int** a, int *x, int choose, int* check)
{
	printf("Enter the value of element x: ");
	scanf("%d", x);
	int count = 0;
	*check = 0;
	if (choose == -1)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (a[i][j] < *x)
				{
					count += 1;
					*check = 1;
				}
			}
		}
	}
	else if (choose == 0)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (a[i][j] == *x)
				{
					count += 1;
					*check = 1;
				}
			}
		}
	}
	else if (choose == 1)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (a[i][j] > *x)
				{
					count += 1;
					*check = 1;
				}
			}
		}
	}
	return count;
}

void displayArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%d, ", *(a+i));
		else printf("%d.\n", *(a+i));
	}
}

int *findMaxEachRows(int rows, int cols, int** a, int *k)
{
	int *mER;
	mER = (int*) malloc((rows+1) * sizeof(int));
	*k = 0;
	for (int i = 0; i < rows; i++)
	{
		int max = INT_MIN;
		for (int j = 0; j < cols; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
			}
		}
		mER[*k] = max;
		*k += 1;
	}	
	return mER;
}

bool isLowerTriangularMatrix(int **a, int rows, int cols)
{
	bool check = false;
	if (rows == cols)
	{
		for (int j = 1; j < cols; j++)
		{
			for (int i = 0; i < j - 1; i++)
			{
				if (a[i][j] == 0)
				{
					check = true;
				}	
				else
				{
					check = false;
					break;
				}		
			}
		}
	}
	else return check;
	
	return check;
}

int main()
{
	// Yeu cau 1
	int rows, cols;
	int** a = insertMatrix(a, &rows, &cols);
	displayMatrix(a, rows, cols);
	
	// Yeu cau 2
	int max1 = findMaxElement(a, rows, cols);
	printf("\nThe maximum value of the matrix is %d.\n", max1);
	int temp;
	Address *sMaxA = saveAddressElement(a, rows, cols, &temp, max1);
	printf("The address of the element(s) with the highest value equals to the maximum value is/are:");
	printAddressElement(sMaxA, temp);
	
	// Yeu cau 3
	int min1 = findMinElement(a, rows, cols);
	printf("\nThe minimum value of the matrix is %d.\n", min1);
	Address *sMinA = saveAddressElement(a, rows, cols, &temp, min1);
	printf("The address of the element(s) with the lowest value equals to the maximum value is/are:");
	printAddressElement(sMinA, temp);
	
	// Yeu cau 4
	int x;
	int max2 = findMaxX(a, rows, cols, &x);
	printf("The maximum value which is less than %d is %d\n", x, max2);
	
	// Yeu cau 5
	int min2 = findMinX(a, rows, cols, &x);
	printf("The minimum value which is greater than %d is %d\n", x, min2);
	
	// Yeu cau 6
	int check;
	int choose = chooseValue(&choose);
	int count1 = countElement(rows, cols, a, &x, choose, &check);
	if (choose == -1) printf("There are %d element with values less than %d!\n", count1, x);
	else if (choose == 0) printf("There are %d element with values equal to %d!\n", count1, x);
	else if (choose == 1) printf("There are %d element with values greater than %d!\n", count1, x);
	
	// Yeu cau 7
	int k3;
	int *mER = findMaxEachRows(rows, cols, a, &k3);
	printf("\nThe maximum value of each rows is:\n");
	displayArray(mER, k3);
	
	// Yeu cau 8
	if (isLowerTriangularMatrix(a, rows, cols)) printf("\nThe matrix is a lower triangular matrix!\n");
	else printf("\nThe matrix isn't a lower triangular matrix!\n");
}