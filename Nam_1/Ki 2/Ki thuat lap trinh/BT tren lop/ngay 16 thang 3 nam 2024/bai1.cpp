#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sach
{
	int ma;
	char tenS[30];
	char tenTG[30];
	float giaTien;
};

void insertBook(Sach* a, int i)
{
	printf("Cuon sach thu %d:\n", i);
	{
		printf("Ma sach: "); 
		scanf("%d", &a->ma);
		
		printf("Ten sach: ");
		fflush(stdin);
		gets(a->tenS);
		
		printf("Ten tac gia: ");
		fflush(stdin);
		gets(a->tenTG);
		
		printf("Gia tien: ");
		scanf("%f", &a->giaTien);
	}
}

Sach* insertBook(int *n, Sach* a)
{
	re:
	printf("Nhap so luong sach: "); 
	scanf("%d", n);
	if (n <= 0)
	{
		printf("So luong sach toi thieu la 1. Vui long nhap lai!\n");
		goto re;
	}
	
	a = (Sach*) malloc((*n+1) * sizeof(Sach));
	
	printf("Nhap thong tin cua %d cuon sach:\n", *n);
	for (int i = 0; i < *n; i++)
	{
		insertBook(&a[i], i);
	}
	
	return a;
}

void displayBook(Sach a)
{
	printf("%10d %30s %30s %30.3f\n", a.ma, a.tenS, a.tenTG, a.giaTien);
}
void displayBook(int n, Sach* a)
{
	for (int i = 0; i < n; i++)
	{
		displayBook(a[i]);
	}
}

Sach* discount(Sach* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].giaTien = a[i].giaTien * 0.2;
	}
	return a;
}

int main()
{
	int n;
	Sach* a = insertBook(&n, a);
	printf("Danh sach thong tin cua %d cuon sach:\n", n);
	displayBook(n, a);
	a = discount(a, n);
	printf("Danh sach thong tin cua %d cuon sach sau khi giam gia la:\n", n);
	displayBook(n, a);
	
}