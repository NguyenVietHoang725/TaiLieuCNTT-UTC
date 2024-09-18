#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
void insertArray(int *n, int **a, int t)
{
	printf("\nNhap so luong phan tu cua day so thu %d: ", t);
	re:
	scanf("%d", n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	*a = (int*) malloc((*n+1) * sizeof(int));
	for (int i = 0; i < *n; i++)
	{
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", *a+i);
	}
}

void printArray(int n, int *a, int t)
{
	printf("Day so thu %d la: ", t);
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%d, ", *(a+i));
		else printf("%d.\n", *(a+i));
	}
}

int findMax(int n, int *a, int *vt)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max < *(a+i))
		{
			max = *(a+i);
			*vt = i;
		}
	}
	return max;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int n, int *a)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (*(a+j) < *(a+j+1))
			{
				swap(&*(a+j), &*(a+j+1));
			}
		}
	}
}
int main()
{
	int n, m;
	int *a, *b;
	
	insertArray(&n, &a, 1);
	printArray(n, a, 1);
	
	insertArray(&m, &b, 2);
	printArray(m, b, 2);
	
	int temp;
	int max1 = findMax(n, a, &temp);
	printf("\nPhan tu lon nhat cua day so thu 1 co gia tri bang %d va nam o vi tri thu %d\n", max1, temp);
	
	int max2 = findMax(m, b, &temp);
	printf("Phan tu lon nhat cua day so thu 2 co gia tri bang %d va nam o vi tri thu %d\n", max2, temp);
	
	printf("\nSau khi sap xep theo thu tu giam dan, ta co:\n");
	bubbleSort(n, a); printArray(n, a, 1);
	bubbleSort(m, b); printArray(m, b, 2);
	
	free(a); free(b);
}