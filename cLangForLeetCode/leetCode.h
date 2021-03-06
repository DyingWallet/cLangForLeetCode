#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"leetCodeStructs.h"

//lc
//lc_1
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
//lc_2
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
//lc_7
int reverse(int x);
//lc_9
bool isPalindrome(int x);
//lc_13
int romanToInt(char* s);
//lc_14
char* longestCommonPrefix(char** strs, int strsSize);
//lc_20
bool isValid(char* s);
//lc_21
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
//lc_29
int divide(int dividend, int divisor);
//lc_67
char* addBinary(char* a, char* b);
//lc_226
treeNode invertTree(treeNode root);
//lc_388
int* countBitsHigh(int num, int* returnSize);
//lc_503
int* nextGreaterElements(int* nums, int numsSize, int* returnSize);
//lc_771
int numJewelsInStones(char* jewels, char* stones);
//lc_1108
char* defangIPaddr(char* address);
//lc_1431
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize);
//lc_1470
int* shuffle(int* nums, int numsSize, int n, int* returnSize);
//lc_1480
int* runningSum(int* nums, int numsSize, int* returnSize);
//lc_1486
int xorOperation(int n, int start);
//lc_1512
int numIdenticalPairs(int* nums, int numsSize);
//lc_1672
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);
//lc_1678
char* interpret(char* command);
//lc_1720
int* decode(int* encoded, int encodedSize, int first, int* returnSize);
//lc_5689
int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue);

//lcp
//lcp_01
int game(int* guess, int guessSize, int* answer, int answerSize);
//lcp_06
int minCount(int* coins, int coinsSize);

//jzOffer
//58_II
char* reverseLeftWords(char* s, int n);

//√Ê ‘Ã‚
//02.03
void deleteNode(struct ListNode* node);