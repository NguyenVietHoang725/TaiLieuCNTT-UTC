#include <stdio.h>
void Nhap(float a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i+1, j+1);
			scanf("%f", &a[i][j]);
		}
	}
}
void Xuat(float a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.3f  ", a[i][j]);
		}
		printf("\n");
	}
}
float TongTCC(float a[][100], int n)
{
	float tong = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			tong += a[i][j];
		}
	}
	return tong;
}
// Tinh tong cac phan tu duoi duong cheo chinh
//float TongDCC(float a[][100], int n)
//{
//	float tong = 0;
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < i-1; i++)
//		{
//			tong += a[i][j];
//		}
//	}
//	return tong;
//}

int main()
{
	int n;
	re1:
	printf("Nhap so bac cua ma tran: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Bac toi thieu la bac 1. Vui long nhap lai!\n");
		goto re1;
	}
	float a[100][100];
	printf("Nhap cac phan tu vao ma tran bac %d:\n", n);
	Nhap(a, n);
	printf("Ma tran bac %d:\n", n);
	Xuat(a, n);
	
	//
	printf("Tong cua cac phan tu nam tren duong cheo chinh bang %.3f\n", TongTCC(a, n));
	
}