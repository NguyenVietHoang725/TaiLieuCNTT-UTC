#include <stdio.h>

struct Diem
{
	float x;
	float y;
};


int main()
{
	int n;
	re1:
	printf("Nhap so luong diem cua day: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("So luong toi thieu la 1. Vui long nhap lai!\n");
		goto re1;
	}
	
	Diem a[100];
	
}