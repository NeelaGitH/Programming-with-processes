#include <stdlib.h>
#include <stdio.h>

// static
int myvar = 80;

int main(){
	int* x = malloc(sizeof(int));
	int* arr = malloc(sizeof(int) * 100);
	
	*x = 120;
	arr[90] = 0xFEEDBEEF;
	arr[101] = 8;
	
	printf("%d\n", arr[101]);
	  
}
