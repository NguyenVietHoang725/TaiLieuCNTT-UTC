#include <stdio.h>
#include <stdlib.h>

// Hàm nhập
void insertArray(int n, int *a){
    for (int i = 0; i < n; i++){
        printf("Enter the element at the index %d: ", i);
        scanf("%d", a+i);
    }
    printf("\n");
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int n){
	if (n <= 1) 
		return false;
	for (int i = 2; i*i <= n; i++){
		if (n % i == 0) 
			return false;
	}
	return true;
}

// Hàm xuất
void printArray(int n, int *a, int mode){
    for (int i = 0; i < n; i++){
    	if (mode == 0)
        	printf("%d ", *(a+i));
        else 
        	if (isPrime(*(a+i)))
        		printf("%d ", *(a+i));
    }
    printf("\n");
}

int main(){
    int n;
    // Nhập số lương số đầu vào
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

    int* a;
    a = (int*)malloc(n * sizeof(int));
    
    // Nhập và xuất dãy số
    insertArray(n, a);
    printf("\nThe Array is: ");
    printArray(n, a, 0);
    
    // Kiểm tra và xuất các số trong dãy là số nguyên tố
    printf("\nThe Prime number Array is: ");
    printArray(n, a, 1);
    
    // Giải phóng bộ nhớ
    free(a);
    
    return 0;
}