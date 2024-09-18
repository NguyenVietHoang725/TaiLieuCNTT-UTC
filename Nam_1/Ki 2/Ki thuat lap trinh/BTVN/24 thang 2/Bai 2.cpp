#include <stdio.h>
#include <math.h>
struct Diem 
{
	float x, y;
	int mau;
};
void Nhap(Diem a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Diem a[%d]:\n");
		printf("\tHoanh do: "); scanf("%f", &a[i].x);
		printf("\tTung do: "); scanf("%f", &a[i].y);
		re2:
		printf("\tMau (0-xanh; 1-do; 2-vang): "); scanf("%d", &a[i].mau);
		if (a[i].mau != 1 && a[i].mau != 2 && a[i].mau != 0)
		{
			printf("Du lieu nhap vao khong thoa man. Vui long nhap lai!\n");
			goto re2;
		}
	}
}
void Xuat(Diem a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("(%.2f, %.2f) - ", a[i].x, a[i].y);
		if (a[i].mau == 0) printf("xanh\n");
		else if (a[i].mau == 1) printf("do\n");
		else if (a[i].mau == 2) printf("vang\n");
	}
}
float TinhGapKhuc(Diem a[], int n)
{
	float gapKhuc = 0;
	for (int i = 0; i < n-1; i++)
	{
		gapKhuc += sqrt(pow(a[i+1].x - a[i].x, 2) + pow(a[i+1].y - a[i].y, 2));
	}
	return gapKhuc;
}
int DemMau(Diem a[], int n, int m)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]. mau == m) dem++;
	}
	return dem;
}
void TraMau(Diem a[], int n, int m)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]. mau == m) printf("(%.2f, %.2f), ", a[i].x, a[i].y);
	}
	printf("\n");
}
void XaGocNhat(Diem a[], int n)
{
	float max = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		float kc = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
		if (kc > max)
		{
			max = kc;
			index = i;
		}
	}
	printf("(%.2f, %.2f)", a[index].x, a[index].y);
}
int main()
{
	int n;
	re1:
	printf("Nhap so luong diem: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	
	Diem a[n];
	printf("Nhap du lieu cua %d diem:\n", n);
	Nhap(a, n);
	printf("Cac diem la:\n");
	Xuat(a, n);
}