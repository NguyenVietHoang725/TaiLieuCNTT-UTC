#include <stdio.h>

// Co vu NDM o ICPC Quoc Gia nha hihihihihi
int main(){
	int a, b, c;
	re:
	printf("nhap a, b, c: ");
	scanf("%d%d%d", &a, &b, &c);
	if ((a + b) < c || (a + c) < b || (b + c) < a) {
		printf("Gia tri nhap vao khong hop le!\n");
		goto re;
	}
	if(a == b && b == c){
		printf("la tam giac deu");
	}else if(a == b || a == c || b == c){
		printf("la tam giac can");
	}else if(a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b){
		printf("la tam giac vuong");
	}else{
		printf("la tam giac thuong");
	}
}