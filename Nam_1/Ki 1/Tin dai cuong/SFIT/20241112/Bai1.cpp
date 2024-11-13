#include <stdio.h>

int main() {
	int ts1, ms1, ts2, ms2;
	printf("Nhap tu so va mau so cua ps1: ");
	scanf("%d%d", &ts1, &ms1);
	printf("Phan so 1 la: ");
	printf("%d / %d\n", ts1, ms1);
	printf("Nhap tu so va mau so cua ps2: ");
	scanf("%d%d", &ts2, &ms2);
	printf("Phan so 2 la: ");
	printf("%d / %d\n", ts2, ms2);
	
	int ts_sum, ms_sum;
	ms_sum = ms1 * ms2;
	ts_sum = ts1 * ms2 + ts2 * ms1;
	printf("Tong hai phan so bang: %d / %d\n", ts_sum, ms_sum);
	
	int ts_mul, ms_mul;
	ts_mul = ts1 * ts2;
	ms_mul = ms1 * ms2;
	printf("Tich hai phan so bang: %d / %d\n", ts_mul, ms_mul);
	
}