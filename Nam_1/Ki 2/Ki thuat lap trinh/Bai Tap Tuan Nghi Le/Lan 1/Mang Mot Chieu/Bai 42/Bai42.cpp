#include <stdio.h>
#include <stdlib.h>

// Hàm nhập
void insertArray(int n, int *a){
    for (int i = 0; i < n; i++){
        printf("Insert element at index %d: ", i);
        scanf("%d", a+i);
    }
    printf("\n");
}

// Hàm đếm số ước
int countDivisors(int n){
	int count = 0;
	for (int i = 1; i <= n; i++){
		if (n % i == 0)
			count += 1;
	}
	
	return count;
}

// Hàm xuất
void printArray(int n, int *a, int mode){
    for (int i = 0; i < n; i++){
    	if (mode == 0)
        	printf("%d ", *(a+i));
        else 
        	if (countDivisors(*(a+i)) >= 3)
        		printf("%d ", *(a+i));
    }
    printf("\n");
}

int main(){
	// Nhập số lượng số nguyên của mảng
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

	// Cấp phát động bộ nhớ
    int* a;
    a = (int*)malloc(n * sizeof(int));
    
    // Nhập và xuất mảng
    insertArray(n, a);
    printf("\nThe Array is: ");
    printArray(n, a, 0);
    
    // Xuất ra màn hình các số có từ 3 ước số trở lên
    printf("\nThe Array of numbers containing Elements with 3 or more divisors: ");
    printArray(n, a, 1);
    
    // Giải phóng bộ nhớ
    free(a);
    
    return 0;
}