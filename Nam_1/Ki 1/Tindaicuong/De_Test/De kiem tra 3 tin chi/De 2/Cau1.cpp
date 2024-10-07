#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
// Gia thiet
struct Diem
{
	float x;
	float y;	
};
void NHAP(Diem a[50], int n)
	{		
		printf("Nhap toa do cua %d diem: \n", n);
		for (int i = 0; i < n; i++)
		{
			printf("(x%d, y%d) = ", i, i); scanf("%f%f", &a[i].x, &a[i].y);
		}
	}
void XUAT(Diem a[50], int n)
{
	printf("Danh sach cac diem vua nhap tu ban phim: ");
	for (int i = 0; i < n; i++)
	{
		printf("(%.2f, %.2f)  ", a[i].x, a[i].y);
	}
}
void YC1(Diem a[50], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].x < 0 && a[i].y < 0) dem++;
	}
	printf("\nCo tat ca %d diem thuoc goc phan tu thu 3!", dem);
}
void YC2(Diem a[50], int n)
{
	float max = sqrt(pow(a[0].x, 2) + pow(a[0].y, 2));
	max = FLT_MIN;
	for (int i = 0; i < n; i++)
	{
		float temp = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (max < temp)
		{
			max = temp;
		}
	}
	printf("\nCac diem xa goc toa do nhat la: ");
	for (int i = 0; i < n; i++)
	{
		float temp2 = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (temp2 == max) printf("(%.2f, %.2f)  ", a[i].x, a[i].y);
	}
}
void YC3(Diem a[50], int n)
{
	int dem1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].y * a[j].y < 0 || (a[i].y == 0 && a[j].y != 0) || (a[i].y != 0 && a[j].y == 0))
			dem1++;
		}
	}
	printf("\nCo tat ca %d doan thang cat truc hoanh!", dem1);
}

main()
{
	int n; printf("Nhap so luong diem can xet: "); scanf("%d", &n);
	Diem a[50];
	NHAP(a, n);
	XUAT(a, n);

	YC1(a, n);
	YC2(a, n);
	YC3(a, n);
}