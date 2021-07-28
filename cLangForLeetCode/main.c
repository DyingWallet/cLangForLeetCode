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
	//cur->val = 1;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 2;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 4;
	//cur->next = NULL;
	//pre = cur;
	////head2
	//cur = head2;
	//cur->val = 1;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 3;
	//cur->next = (listNode)calloc(1, sizeof(listNode));
	//pre = cur;
	//cur = cur->next;
	//cur->val = 4;
	//cur->next = NULL;
	//pre = cur;

	//struct ListNode* res = mergeTwoLists(head1, head2);
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
	//int nums[5] = { 1,2,5,4,3 };
	//int returnSize = 0;
	//int*res = nextGreaterElements( nums, 5, &returnSize);

	//char* s = "([)]";
	//bool res = isValid(s);

	//char* res = countAndSay(5);
	//int nums[] = { 1,-1,1 };
	//int numsSize = 3;

	//int res = maxSubArray(nums, numsSize);
	//char* s = "Hello World";
	//int res = lengthOfLastWord(s);
	//treeNode head = (treeNode)calloc(1,sizeof(struct TreeNode));
	//treeNode temp = head;
	//head->val = 2;
	//head->left = (treeNode)calloc(1,sizeof(struct TreeNode));
	//head->left->val = 2;

	//head->right = (treeNode)calloc(1,sizeof(struct TreeNode));
	//head->right->val = INT_MAX;

	//temp = head->right;

	//temp->left = (treeNode)calloc(1,sizeof(struct TreeNode));
	//temp->left->val = 5;

	//temp->right = (treeNode)calloc(1,sizeof(struct TreeNode));
	//temp->right->val = 7;

	//int res = findSecondMinimumValue(head);

	//char s[] = "abbaca";
	//char* res = removeDuplicates_1047(s);
	//int buf = 3;
	//char c1 = (char)buf, c2 = buf + '0';

	//printf("c1:%c\nc2:%c", c1, c2);
	//int m = 3, n = 3, nums1Size = 6, nums2Size = 3;
	//int nums1[] = { 1,2,3,0,0,0 };
	//int nums2[] = { 2,3,4 };

	//merge(nums1, nums1Size, m, nums2, nums2Size, n);

	int numbers[] = { 1, 2, 3, 4, 4, 9, 56, 90 };
	int target = 8;
	int returnSize = 0;

	int* res = twoSum_167(numbers, 8, target, &returnSize);

	for (int i = 0; i < returnSize; i++) {
		printf("%d", res[i]);
	}
	return 0;
}