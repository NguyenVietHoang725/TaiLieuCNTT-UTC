#include <stdio.h>

void NhapDay(int a[], int n)
{
	printf("Nhap %d phan tu vao day so:\n");
	for (int i = 0; i < n; i++)
	{
		printf("\tPhan tu a[%d] = ", i+1);
		scanf("%d", &a[i]);
	}
}
void XuatDay(int a[], int n)
{
	printf("Day so vua nhap la: ");
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%d, ", a[i]);
		else printf("%d.", a[i]);
	}
}

int TongDaySo(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i];
	}
	return tong;
}
int LonHonX(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x) dem++;
	}
	return dem;
}
int TimMax(int a[], int n)
{
	int max;
	for (int i = 0; i < n; i++)
	{
		if (max < a[i]) max = a[i];
	}
	return max;
}
bool KTTangDan(int a[], int n)
{
	bool tangDan = true; 
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] > a[i+1]) 
		{
			tangDan = false;
			return tangDan;
		}
	}
	return tangDan;
}
int main()
{
	// 
	int n;
	re:
	printf("Nhap vao so luong phan tu cua day so: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	//
	int a[n];
	NhapDay(a, n);
	XuatDay(a, n);
	
	// 
	printf("\nTong cua day so bang %d", TongDaySo(a, n));
	
	// 
	int x;
	printf("\nNhap so nguyen x: ");
	scanf("%d", &x);
	printf("Co tat ca %d phan tu trong day lon hon x", LonHonX(a, n, x));
	
	// 
	printf("\nPhan tu lon nhat trong day so la %d", TimMax(a, n));
	
	// 
	if (KTTangDan(a, n) == true) printf("\nDay so tang dan!");
	else printf("\nDay so khong tang dan!");
}