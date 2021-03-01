#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leetCode.h"

int main() {
	char* add = "255.100.50.0";
	char* res = defangIPaddr(add);
	printf("%s", res);
	return 0;
}