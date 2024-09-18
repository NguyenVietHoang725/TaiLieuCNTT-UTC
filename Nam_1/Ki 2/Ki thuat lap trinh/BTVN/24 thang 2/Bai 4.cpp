#include <stdio.h>
#include <limits.h>
void NhapDay(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i+1);
		scanf("%d", &a[i]);
	}
}
void XuatDay(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1)
			printf("%d, ", a[i]);
		else 
			printf("%d.\n", a[i]);
	}
}
bool KiemTraDoiXung(int a[], int n)
{
	bool doiXung = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != a[n-1-i])
		{
			doiXung = false;
			return doiXung;
		}
	}
	return doiXung;
}
int TimMaxChia3(int a[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 3 == 0)
		{
			if (a[i] > max) max = a[i];
		}
	}
	return max;
}
int main()
{
	int n;
	re1:
	printf("Nhap so luong phan tu cua day so: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	
	int a[n];
	printf("Nhap %d phan tu vao day so:\n", n);
	NhapDay(a, n);
	printf("Day so vua nhap la: ");
	XuatDay(a, n);
	
	// 
	if (KiemTraDoiXung(a, n))
	{
		printf("Day doi xung!\n");
	}
	else printf("Day khong doi xung\n");
	
	//
	printf("Phan tu chia het cho 3 lon nhat trong day la: %d", TimMaxChia3(a, n));
}