#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leetCode.h"

int main() {
	int arr[] = { 2,5,1,3,4,7 };
	int *res=NULL;
	int n = 3;
	int retSize;
	res = shuffle(arr,6,n,&retSize);

	for (int i = 0; i < retSize; i++) {
		printf_s("%d,", res[i]);
	}

	return 0;
}