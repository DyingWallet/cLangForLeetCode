#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leetCode.h"

int main() {
	int arr[] = { 2,3,5,1,3 };
	int ext = 3;
	int len = 5;
	int* retLen = 5;
	kidsWithCandies(arr,len,ext, &retLen);

	return 0;
}