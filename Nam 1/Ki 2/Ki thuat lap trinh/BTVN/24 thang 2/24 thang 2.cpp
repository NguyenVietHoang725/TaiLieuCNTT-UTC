#include <stdio.h>
#include <string.h>
struct SinhVien
{
	char maSinhVien[10];
	char tenSinhVien[30];
	float diem;
	int lop;
};

void NhapDS(SinhVien a[], int n)
{
	printf("Nhap thong tin cua %d sinh vien:\n", n);
	for (int i = 0; i < n; i++)
	{
		printf("Sinh vien thu %d:\n", i+1);
		printf("\tMa sinh vien: "); fflush(stdin); gets(a[i].maSinhVien);
		printf("\tTen sinh vien: "); fflush(stdin); gets(a[i].tenSinhVien);
		re1:
		printf("\tDiem: "); scanf("%f", &a[i].diem);
		printf("\tLop (1/2/3): "); scanf("%d", &a[i].lop);
		if (a[i].lop != 1 && a[i].lop != 2 && a[i].lop != 3)
		{
			printf("Chi ton tai lop 1, 2 hoac 3. Vui long nhap lai!\n");
			goto re1;
		}
	}
}
void XuatDS(SinhVien a[], int n)
{
	printf("Danh sach sinh vien:\n");
	
	
	for (int i = 0; i < n; i++)
	{
		printf("%3d %10s %30s %7.2f %4d\n", i+1, a[i].maSinhVien, a[i].tenSinhVien, a[i].diem, a[i].lop);
	}
}
void NhoHonX(SinhVien a[], int n, float x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].diem < x)
		{
			printf("%3d %10s %30s %7.2f %4d\n", i+1, a[i].maSinhVien, a[i].tenSinhVien, a[i].diem, a[i].lop);
		}
	}
}
void LonHonX(SinhVien a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].diem > x)
		{
			printf("%3d %10s %30s %7.2f %4d\n", i+1, a[i].maSinhVien, a[i].tenSinhVien, a[i].diem, a[i].lop);
		}
	}
}
void BangX(SinhVien a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].diem == x)
		{
			printf("%3d %10s %30s %7.2f %4d\n", i+1, a[i].maSinhVien, a[i].tenSinhVien, a[i].diem, a[i].lop);
		}
	}
}
void ThongKeLop(SinhVien a[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		
	}
}
int main()
{
	int n; 
	re:
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	//
	SinhVien a[n];
	NhapDS(a, n);
	XuatDS(a, n);
	
	// 
	float diemChuan;
	re2:
	printf("Nhap diem chuan: ");
	scanf("%f", &diemChuan);
	if (diemChuan < 0 || diemChuan > 10)
	{
		printf("Diem chuan duoc nhap khong thoa man. Vui long nhap lai!\n");
		goto re2;
	}
	printf("Cac sinh vien truot mon la:\n");
	NhoHonX(a, n, diemChuan);
	
	//
	float diemX;
	re3:
	printf("Nhap diem bat ky: ");
	scanf("%f", &diemX);
	if (diemX < 0 || diemX > 10)
	{
		printf("Diem duoc nhap khong thoa man. Vui long nhap lai!\n");
		goto re3;
	}
	printf("Cac sinh vien co diem nho hon %.2f la:\n", diemX);
	NhoHonX(a, n, diemX);
	printf("Cac sinh vien co diem lon hon %.2f la:\n", diemX);
	LonHonX(a, n, diemX);
	printf("Cac sinh vien co diem bang %.2f la:\n", diemX);
	BangX(a, n, diemX);
	
	//
	
}