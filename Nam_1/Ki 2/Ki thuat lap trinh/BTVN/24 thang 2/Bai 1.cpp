#include <stdio.h>
#include <math.h>
void Nhap(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i+1, i+1);
			scanf("%d", &a[i][j]);
		}
	}
}
void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d   ", a[i][j]);
		}
		printf("\n");
	}
}
float TinhTBCChan(int a[][100], int m, int n)
{
	int dem = 0, tong = 0;
	float TBC = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				tong += a[i][j];
				dem++;
			}
		}
	}
	TBC = tong*1.0 / dem;
	return TBC;
}
float TinhTBNLe(int a[][100], int m, int n)
{
	int dem = 0, tich = 1;
	float TBN = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				tich *= a[i][j];
				dem++;
			}
		}
	}
	TBN = pow(tich, 1.0/dem);
	return TBN;
}
int main()
{
	int m, n;
	re1:
	printf("Nhap so hang cua ma tran: ");
	scanf("%d", &m);
	if(m <= 0)
	{
		printf("So hang toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	re2:
	printf("Nhap so cot cua ma tran: ");
	scanf("%d", &n);
	if(n <= 0)
	{
		printf("So cot toi thieu la 1. Vui long nhap lai!\n");
		goto re2;
	}
	
	int a[100][100];
	printf("Nhap cac phan tu vao ma tran A co %d x %d:\n", m, n);
	Nhap(a, m, n);
	printf("Ma tran A co %d x %d la:\n", m, n);
	Xuat(a, m, n);
	
	printf("Trung binh cong cua cac phan tu chan trong ma tran A bang %.2f\n", TinhTBCChan(a, m, n));
	
	printf("Trung binh nhan cua cac phan tu le trong ma tran A bang %.2f\n", TinhTBNLe(a, m, n));
	
	return 0;
}