#include <stdio.h>

struct PS
{
	int ts;
	int ms;
};

void NhapPS(PS *px)
{
	printf("\tNhap tu so: "); scanf("%d", &px->ts);
	re:
	printf("\tNhap mau so: "); scanf("%d", &px->ms);
	if (px->ms == 0)
	{
		printf("Mau so phai khac 0. Vui long nhap lai!\n");
		goto re;
	}
}

void XuatPS(PS x)
{
	printf("%d / %d\n", x.ts, x.ms);
}

int TimUSCLN(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

PS RutGonPS(PS *x)
{
	int uoc = TimUSCLN(x->ts, x->ms);
	x->ts = x->ts / uoc;
	x->ms = x->ms / uoc;
	return *x;
}

PS TinhTong2PS(PS a, PS b)
{
	PS t;
	t.ms = a.ms * b.ms;
	t.ts = a.ts * b.ms + b.ts * a.ms;
	RutGonPS (&t);
	return t;
}

PS TangPS1DV(PS a)
{
	a.ts = a.ts + a.ms;
	RutGonPS(&a);
	return a;
}

int SoSanh2PS(PS a, PS b)
{
	float gt1 = a.ts*1.0 / a.ms;
	float gt2 = b.ts*1.0 / b.ms;
	if (gt1 > gt2) return 1;
	else if (gt1 == gt2) return 0;
	else return -1;
}

bool LonHon1(PS a)
{
	bool test = true;
	float gt = a.ts*1.0 / a.ms;
	if (gt > 1) return test;
	else 
	{
		test = false;
		return test;
	}
}

PS NghichDaoPS(PS a)
{
	int temp = a.ts;
	a.ts = a.ms;
	a.ms = temp;
	RutGonPS(&a);
	return a;
}
int main()
{
	
	PS a, b;
	// Nhap phan so thu nhat
	printf("Nhap phan so thu nhat:\n"); NhapPS(&a);
	printf("Phan so thu nhat la:\n"); XuatPS(a);
	// Nhap phan so thu hai
	printf("\nNhap phan so thu hai:\n"); NhapPS(&b);
	printf("Phan so thu hai la:\n"); XuatPS(b);
	
	// Tinh tong hai phan so
	printf("\nTong cua hai phan so bang "); XuatPS(TinhTong2PS(a, b));
	
	// Tang phan so thu hai them 1 don vi
	printf("\nPhan so thu hai sau khi tang 1 don vi la: "); XuatPS(TangPS1DV(b));
	
	// So sanh hai phan so
	if (SoSanh2PS(a, b) == 1) printf("\nPhan so thu nhat lon hon phan so thu hai\n");
	else if (SoSanh2PS(a, b) == -1) printf("\nPhan so thu nhat nho hon phan so thu hai\n");
	else if (SoSanh2PS(a, b) == 0) printf("\nPhan so thu nhat bang phan so thu hai\n");
	
	// Kiem tra xem phan so thu nhat co lon hon 1 hay khong
	if (LonHon1(a)) printf("\nPhan so thu nhat lon hon 1\n");
	else printf("\nPhan so thu nhat khong lon hon 1\n");
	
	// Nghich dao phan so thu hai
	printf("\nPhan so thu hai sau khi nghich dao la: "); XuatPS(NghichDaoPS(b));
}