#include <stdio.h>
int main(void)
{ 
 int n, i, j;
 float a[10][10], tg, T, S;
 printf("Nhap n = "); scanf("%d",&n);
 printf("\nNhap ma tran vuong A:\n");
 for(i = 1; i <= n; i++)
 for(j = 1; j <= n; j++) 
 {
 printf("Nhap a[%d][%d] = ", i,j);
 scanf("%f",&tg); a[i][j] = tg;
 }
 printf("\n\nMa tran A\n\n");
 for(i = 1; i <= n; i++) {
 for(j = 1; j <= n; j++) 
printf("%7.2f ",a[i][j]);
 printf("\n");
 }
 S = 0.0;
 for(i = 1; i <= n; i++)
 for(j = i + 1; j <= n; j++) 
S += a[i][j];
 printf("\nTong gia tri cac pt phia tren dcc: %0.2f",S);
 T = 1;
 for(i = 1; i <= n; i++)
 for(j = 1; j <= n; j++) 
 if(a[i][j] > 5.0 && a[i][j] < 20.0) 
 T *= a[i][j];
 printf("\nTich gia tri cac pt thuoc (5, 20): %0.2f", T);
}