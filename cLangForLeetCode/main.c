#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leetCode.h"

typedef struct ListNode* listNode;

int main() {
	//listNode pre = NULL, cur = NULL;
	//listNode head1 = (listNode)calloc(1, sizeof(struct ListNode));
	//listNode head2 = (listNode)calloc(1, sizeof(struct ListNode));
	//cur = head1;
	//cur->val = 2;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 4;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 9;
	//cur->next = NULL;
	//pre = cur;
	////head2
	//cur = head2;
	//cur->val = 5;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 6;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 4;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 9;
	//cur->next = NULL;
	//pre = cur;
	//listNode res = addTwoNumbers(head1, head2);
	//printf("%d\n",head1->val);

	//char* str = addBinary("11", "1");
	//printf("%s\n", str);
	//int len = 3;
	//int(*hashMap)[2] = (int(*)[2])calloc(len, sizeof(int[2]));
	//for (int i = 0; i < len; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		hashMap[i][j] = i + j;
	//		printf("%d,", hashMap[i][j]);
	//	}
	//}
	//bool res = isPalindrome(1001);
	//printf("%d\n", num/10);
	int nums[5] = { 1,2,5,4,3 };
	int returnSize = 0;
	int*res = nextGreaterElements( nums, 5, &returnSize);

	return 0;
}