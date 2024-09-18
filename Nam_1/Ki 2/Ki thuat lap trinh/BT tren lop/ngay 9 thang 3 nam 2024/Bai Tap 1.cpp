#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
void Nhap(int *n, int **a)
{
	printf("Nhap n: ");
	scanf("%d", n);
	*a = (int*) malloc((*n+1) * sizeof(int));
	for(int i=0;i<*n;i++)
	{
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", *a+i);
	}
}

void Xuat(int n, int *a)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%d, ", *(a+i));
		else printf("%d.\n", *(a+i));
	}
}

int TimMax(int n, int *a)
{
	int max = INT_MIN;
	for (int i = 0; i< n; i++)
	{
		if (max < *(a+i))
		{
			max = *(a+i);
		}
	}
	return max;
}

void SapXep(int n, int *a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			int temp = *(a+i);
			if (temp > *(a+i))
			{
				*(a+i) = *(a+j);
				*(a+j) = temp;
			}
		}	
	}
}
int main()
{
	int n;
	int *a, *b;
	Nhap(&n, &a);
	printf("Day so thu nhat la: ");
	Xuat(n, a);
	
	Nhap(&n, &b);
	printf("Day so thu hai la: ");
	Xuat(n, b);
	
	printf("Phan tu lon nhat trong day thu nhat la %d\n", TimMax(n, a));
	printf("Phan tu lon nhat trong day thu hai la %d\n", TimMax(n, b));
	
	printf("Sau khi sap xep theo thu tu giam dan\n");
	printf("Day thu nhat la: "); SapXep(n, a); Xuat(n, a);
	printf("Day thu hai la: "); SapXep(n, b); Xuat(n, b);
}