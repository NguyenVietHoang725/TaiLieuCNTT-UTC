#include<stdio.h>

int main(){
	int a=10,i=0;

	i=++a + ++a + a++;
	printf("%d\n", a);
	printf("%d\n", i);
	i=a++ + ++a + ++a;
	a=++a + ++a + a++;
	
	printf("%d\n", a);
	printf("%d\n", i);
}