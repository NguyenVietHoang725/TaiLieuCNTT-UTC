#include <stdio.h>
#include <string.h>
#include <float.h>
#include <limits.h>
struct ThiSinh
{
	char hoten[30];
	float diem;
	char truong;
};

void Nhap(ThiSinh a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Thi sinh %d:\n", i+1);
		printf("Ho va ten: "); fflush(stdin); gets(a[i].hoten);
		printf("Diem: "); scanf("%f", &a[i].diem);
		re2:
		printf("Truong (A/B/C): "); fflush(stdin); scanf("%c", &a[i].truong);
		if (a[i].truong != 'A' && a[i].truong != 'B' && a[i].truong != 'C')
		{
			printf("Du lieu nhap vao khong thoa man. Vui long nhap lai!\n");
			goto re2;
		}
	}
}

void XuatTS(ThiSinh a)
{
	printf("%20s %10.2f %7c\n", a.hoten, a.diem, a.truong);
}

void Xuat(ThiSinh a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		XuatTS(a[i]);
	}
}

float TinhTongDiem(ThiSinh a[], int n, char b)
{
	float tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == b)
		{
			tong += a[i].diem;
		}
	}
	return tong;
}
int ThamDu(ThiSinh a[], int n, char b)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == b)
		{
			dem++;
		}
	}
	return dem;
}
ThiSinh ThiSinhMax(ThiSinh a[], int n, char b)
{
	ThiSinh x;
	x.diem = FLT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (a[i].truong == 'A')
		{
			if (a[i].diem > x.diem)
			{
				x = a[i];
			}
		}
	}
	return x;
}
int main()
{
	// Nhap so luong thi sinh dau vao
	int n;
	re1:
	printf("Nhap so luong thi sinh: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	
	// Nhap va xuat danh sach thi sinh
	ThiSinh a[n];
	printf("Nhap thong tin cua %d thi sinh:\n");
	Nhap(a, n);
	printf("Danh sach thi sinh:\n");
	Xuat(a, n);
	
	// Tinh tong diem cua cac thi sinh cua moi truong
	printf("Tong diem truong A: %.2f\n", TinhTongDiem(a, n, 'A'));
	printf("Tong diem truong B: %.2f\n", TinhTongDiem(a, n, 'B'));
	printf("Tong diem truong C: %.2f\n", TinhTongDiem(a, n, 'C'));
	
	// Thong ke so thi sinh tham du cua moi truong
	printf("Co %d thi sinh tham du den tu truong A\n", ThamDu(a, n, 'A'));
	printf("Co %d thi sinh tham du den tu truong B\n", ThamDu(a, n, 'B'));
	printf("Co %d thi sinh tham du den tu truong C\n", ThamDu(a, n, 'C'));
	
	// Tim thi sinh co diem lon nhat cua truong A
	ThiSinh t  = ThiSinhMax(a, n, 'A');
	printf("Thi sinh co diem cao nhat cua truong A la:\n"); XuatTS(t);
}