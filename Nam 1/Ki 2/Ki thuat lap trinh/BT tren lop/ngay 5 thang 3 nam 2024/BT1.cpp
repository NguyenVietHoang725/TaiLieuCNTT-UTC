#include <stdio.h>
struct PhanSo
{
	int ts;
	int ms;
};
void NhapPS(PhanSo *a)
{
	printf("Nhap tu so: ");
	scanf("%d", &a->ts);
	re1:
	printf("Nhap mau so: ");
	scanf("%d", &a->ms);
	if (a->ms == 0)
	{
		printf("Mau so phai khac 0. Vui long nhap lai!\n");
		goto re1;
	}
}
void XuatPS(PhanSo a)
{
	printf("%d / %d\n", a.ts, a.ms);
}

PhanSo TinhTong(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.ts = a.ts*b.ms + b.ts*a.ms;
	c.ms = a.ms*b.ms;
	return c;
}
PhanSo Tang1DV(PhanSo a)
{
	PhanSo c;
	c.ts = a.ts + a.ms;
	c.ms = a.ms;
	return c;
}
int SoSanhPS(PhanSo a, PhanSo b)
{	
	if (a.ts / a.ms > b.ts / b.ms)
	{
		return 1;
	}
	else if (a.ts / a.ms < b.ts / b.ms)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
bool LonHon1(PhanSo a)
{
	bool test = true;
	float temp = a.ts / a.ms;
	if (temp > 1)
	{
		return test;
	}
	else 
	{
		test = false;
		return test;
	}
}
int main()
{
	PhanSo a, b;
	
	printf("Nhap lan luot 2 phan so:\n");	
	NhapPS(&a); NhapPS(&b);

	printf("Hai phan so vua nhap la:\n");
	XuatPS(a); XuatPS(b);

	TinhTong(a, b);
	PhanSo c = TinhTong(a, b);
	printf("Tong hai phan so bang "); XuatPS(c);
	
	c = Tang1DV(a); printf("Phan so a sau khi tang 1 don vi la: "); XuatPS(c);
	
	if (SoSanhPS(a, b) == 0) printf("Hai phan so bang nhau\n");
	if (SoSanhPS(a, b) == 1) printf("Phan so 1 lon hon phan so 2\n");
	if (SoSanhPS(a, b) == -1) printf("Phan so 1 nho hon phan so 2\n");
	
	if (LonHon1(b)) printf("Phan so a lon hon 1\n");
	else printf("Phan so a khong lon hon 1\n");
}