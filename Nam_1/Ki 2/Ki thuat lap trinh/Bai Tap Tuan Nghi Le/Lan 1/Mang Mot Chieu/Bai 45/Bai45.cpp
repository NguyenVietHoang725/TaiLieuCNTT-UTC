#include <stdio.h>
#include <stdlib.h>

void insertArray(int n, int *a){
    for (int i = 0; i < n; i++){
        printf("Enter the element at the index %d: ", i);
        scanf("%d", a+i);
    }
    printf("\n");
}

bool isPrime(int n){
	if (n <= 1) 
		return false;
	for (int i = 2; i*i <= n; i++){
		if (n % i == 0) 
			return false;
	}
	return true;
}

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

float averagePrimeNum(int n, int *a){
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		if (isPrime(*(a+i))){
			sum += *(a+i);
			cnt += 1;
		}
	}
	
	return (float)sum / cnt;
}

int main(){
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

    int* a;
    a = (int*)malloc(n * sizeof(int));
    
    insertArray(n, a);
    printf("\nThe Array is: ");
    
    printArray(n, a, 0);
    
    printf("\nThe Prime number Array is: ");
    printArray(n, a, 1);
    
    printf("\nThe average of the elements that are prime numbers in the array is equal to %.2f", averagePrimeNum(n, a));
    
    free(a);
    
    return 0;
}