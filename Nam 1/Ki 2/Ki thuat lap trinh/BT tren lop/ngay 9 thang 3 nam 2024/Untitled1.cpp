#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
void Nhap(int n, int *a)
{
	for (int i = 0; i < n; i++) // a la dia chi, *a la gia tri 
	{
		printf("Nhap phan tu thu %d:\n", i+1);
		scanf("%d", a+i);
	}
}

void Xuat(int n, int *a)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1) printf("%d, ", *(a+i));
		else printf("%d.", *(a+i));
	}
}

int TinhTongLonHonX(int n, int x, int *a, int *check)
{
	int s = 0;
	*check = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a+i) > x) 
		{
			s += *(a+i);
			*check = 1;
		}
	}
	return s;
}

float TinhTBCChan(int n, int *a, int *check)
{
	float tbc = 0; 
	int dem = 0;
	*check = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a+i) % 2 == 0) 
		{
			tbc += *(a+i);
			dem++;
			*check = 1;
		}
	}
	
	return tbc / dem;
}

int TimMax(int n, int *a, int *vt)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max < *(a+i))
		{
			max = *(a+i);
			*vt = i;
		}
	}
	return max;
}

int *TimLonHonX(int n, int *a, int x, int *k)
{
	int *pt;
	pt = (int*) malloc((n+1) * sizeof(int));
	*k = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a+i) > x)
		{
			pt[*k] = *(a+i);
			*k+=1;
		}
	}
	return pt;
}
int main()
{
	int n, *a;
	printf("Nhap n: "); scanf("%d", &n);
	
	// Cap phat bo nho dong sau khi nhap n
	a = (int*) malloc((n+1) * sizeof(int));
	
	// Nhap va xuat
	Nhap(n, a);
	Xuat(n, a);
	
	// Tinh tong cac phan tu lon hon x
	int x; printf("\nNhap x: "); scanf("%d", &x);
	int c;
	int t1 = TinhTongLonHonX(n, x, a, &c);
	if (c == 0) printf("Khong co phan tu nao lon hon x\n");
	else printf("Tong cua cac phan tu lon hon x bang %d\n", t1);
	
	// Tinh trung binh cong cua cac phan tu chan
	float t2 = TinhTBCChan(n, a, &c);
	if (c == 0) printf("Khong co phan tu chan nao\n");
	else printf("Trung binh cong cua cac phan tu chan trong day bang %.2f\n", t2);
	
	// Tim Max va vi tri cua Max
	int vtMax;
	int t3 = TimMax(n, a, &vtMax);
	printf("Phan tu lon nhat trong day co gia tri bang %d va nam o vi tri thu %d\n", t3, vtMax);
	
	// Tim cac phan tu lon hon x trong day
	int k;
	int *kq = TimLonHonX(n, a, x, &k);
	printf("Cac phan tu lon hon x la: ");
	Xuat(k, kq);
	
	// Cho biet cac cap so lien tiep thoa man tinh chat tich chia het cho tong
	
	
	// giai phong con tro
	free(a); 
}