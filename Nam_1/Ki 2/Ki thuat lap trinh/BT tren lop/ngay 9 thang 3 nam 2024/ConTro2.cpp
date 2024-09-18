// nhap vao day so a (int) có n phan tu
// tinh tong cac phan tu lon hon x
// tinh TBC cac phan tu chan
#include<stdio.h>
#include<stdlib.h>
void nhap(int *n, int **a){ // dia chi a, gia tri *a
	printf("Nhap n: ");
	scanf("%d", n);
	*a = (int*) malloc((*n+1) * sizeof(int));
	for(int i=0;i<*n;i++){
		printf("Nhap ptu thu %d: ", i);
		scanf("%d", *a+i);
	}
}
void xuat(int n, int *a){
	for(int i=0;i<n;i++)
		printf("%d ", *(a+i));
}
int tong(int n, int *a, int x, int *check){
	int s = 0;
	*check = 0;
	for(int i=0;i<n;i++){
		if(*(a+i) >  x){
			s+=*(a+i);
			*check = 1;
		}
	}
	return s;
}
// tinh TBC cac phan tu chan
float tbc(int n, int *a, int *check){
	int s = 0;
	int d = 0;
	*check = 0;
	for(int i=0;i<n;i++){
		if(*(a+i) % 2 == 0){
			s += *(a+i);
			d+=1;
			*check = 1;
		}
	}
	return (float)s/d; // 1.0*s/d;
}
// tim gia tri lon nhat cua day so va 1 vi tri chua max
int gtln(int n, int *a, int *vt){
	int m = *(a+0);
	*vt = 0;
	for(int i=0;i<n;i++){
		if(*(a+i) > m){
			m = *(a+i);
			*vt = i;
		}
	}
	return m;
}

// cho biet cac phan tu lon hon x trong day
int *tim(int n, int *a, int x, int *k){
	int *pt;
	pt = (int*) malloc((n+1) * sizeof(int));
	*k = 0;
	for(int i=0;i<n;i++){
		if(*(a+i) > x){
			pt[*k] = *(a+i);
			*k+=1;			
		}
	}
	return pt;
}

// cho biet cac cap so lien tiep thoa man tinh chat tich
// chia het cho tong

int main(){
	int n;
	int *a;
	nhap(&n, &a);
	xuat(n, a);
	int k;
	int *kq = tim(n, a, 5, &k);
	printf("\nCac phan tu lon hon 5 la: ");
	xuat(k, kq);
//	int c;
//	int t = tong(n, a, 3, &c);
//	if(c == 0)
//		printf("\nKhong co phan tu nao lon hon x");
//	else
//		printf("\ntong la: %d", t);
//		
//	float tb = tbc(n, a, &c);
//	if(c == 0)
//		printf("\nKhong co phan tu nao chan");
//	else
//		printf("\ntbc la: %.2f", tb);
	//free(a);
}

