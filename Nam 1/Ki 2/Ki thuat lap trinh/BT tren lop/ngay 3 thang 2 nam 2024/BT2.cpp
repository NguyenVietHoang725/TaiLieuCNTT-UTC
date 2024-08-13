#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
void Nhap(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap he so a[%d]: ", i+1);
		scanf("%f", &a[i]);
	}
}
void Xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0) printf("%.2f + ", a[i]);
		else if (i != 0 && i < n-1) printf("%.2f * x^%d + ", a[i], i);
		else printf("%.2f * x^%d\n", a[i], i);
	}
}
float ThaySo(float a[], int n, int d)
{
	float kq = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0) kq += a[i];
		else kq += a[i] * pow(d, i);
	}
	return kq;
}
float Chia(float p[], float q[], int n, int m, int d)
{
	float hs1 = ThaySo(p, n, d);
	float hs2 = ThaySo(q, m, d);
	float kq = hs1 / hs2;
	return kq;
}
float HeSoMax(float a[], int n)
{
	float max = FLT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}
float TinhBieuThuc(float p[], float q[], int n, int m)
{
	float maxP = HeSoMax(p, n);
	float maxQ = HeSoMax(q, m);
	float tong = maxP + maxQ;
	return tong;
}
int main()
{
	int n, m;
	printf("Nhap lan luot bac cua 2 da thuc P va Q: ");
	scanf("%d%d", &n, &m);
	float p[100], q[100];
	Nhap(p, n); printf("P = ");
	Xuat(p, n);
	Nhap(q, m); printf("Q = ");
	Xuat(q, m);
	
	//
	float d; 
	printf("Nhap so d bat ki: "); scanf("%f", &d);
	printf("Ket qua cua phep tinh bang %.2f\n", Chia(p, q, n, m, d));
	
	//
	printf("Gia tri cua bieu thuc bang %.2f", TinhBieuThuc(p, q, n, m));
}