#include <stdio.h>
#include <string.h>

struct SACH
{
	char ma[20];
	char ten[20];
	char tg[20];
	float price;
};
main()
{
	int n; printf("Nhap so luong sach: "); scanf("%d", &n);
	SACH a[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap thong tin cua cuon sach thu %d:\n", i+1);
		fflush(stdin);
		printf("Nhap ma sach: "); gets(a[i].ma);
		printf("Nhap ten sach: "); gets(a[i].ten);
		printf("Nhap ten tac gia: "); gets(a[i].tg);
		printf("Nhap gia tien: "); scanf("%f", &a[i].price);
		printf("\n");
	}
	printf("Danh sach nhung cuon sach vua nhap la: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%10s %10s %10s %10.2f\n", a[i].ma, a[i].ten, a[i].tg, a[i].price);
	}
	
	// Yeu cau 1
	fflush(stdin);
	char tentg[20];
	printf("Nhap ten tac gia can tim: "); gets(tentg);
	printf("Nhung cuon sach cua tac gia tren la: ");
	for (int i = 0; i < n; i++)
	{
		if(strcmp(a[i].tg,tentg)==0) printf("%s, ", a[i].ten);
	}
	
	// Yeu cau 2
	float max = a[0].price;
	printf("\nCuon sach dat nhat la: ");
	for (int i = 0; i < n; i++)
	{
		if (max < a[i].price) max = a[i].price;
	}
	printf("%s\n", max);
	
	// Yeu cau 3
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].price > 100) dem++;
	}
	printf("\nCo tat ca %d cuon sach co gia lon hon 100!", dem);
}