#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

void insertArray(int n, float *a){
	for (int i = 0; i < n; i++){
		printf("Enter the element at the index %d: ", i);
		scanf("%f", a+i);
	}
}

void printArray(int n, float *a){
	for (int i = 0; i < n; i++){
		if (i != n-1)
			printf("%.2f, ", *(a+i));
		else 
			printf("%.2f.\n", *(a+i));
	}
}

int findIndexMaxNegativeNumber(int n, float *a){
	float max = 0;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (max > *(a+i)){
			max = *(a+i);
		}
		if (max < *(a+i) && *(a+i) < 0)
		{
			max = *(a+i);
			index = i;
		}
	}
	
	return index;
}

int main(){
	int n;
	printf("Enter the number of elements of the Array: ");
	scanf("%d", &n);
	
	float *a;
	a = (float*)malloc(n * sizeof(float));
	
	insertArray(n, a);
	printf("The Array is: ");
	printArray(n, a);
	
	int index = findIndexMaxNegativeNumber(n, a);
	if (index == -1)
		printf("The Array doesn't contain any negative elements.");
	else 
		printf("The largest negative element in the Array at the index %d", index);
	
	free(a);
	
	return 0;
}