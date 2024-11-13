#include <stdio.h>

int main() {
	int gio, phut;
	printf("Nhap gio va phut: ");
	scanf("%d%d", &gio, &phut);
	
	if (gio < 0 || phut < 0) {
		printf("Gia tri nhap vao khong hop le!\n");
	} else {
			int giay = gio * 3600 + phut * 60;
		printf("Tong so giay la: %d\n", giay);
	}
}