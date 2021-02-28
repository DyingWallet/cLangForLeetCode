//给定字符串J?代表石头中宝石的类型，和字符串S代表你拥有的石头。
//S中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
//J?中的字母不重复，J和S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
//示例 1:
//输入: J = "aA", S = "aAAbbbb"
//输出 : 3
//示例 2 :
//输入 : J = "z", S = "ZZ"
//输出 : 0
#include"leetCode.h"
#define HASH_SIZE 52
#define UPPER_LETTER 65
#define LOWER_LETTER 71
#define MIN_CHAR (char)'A' - 1

bool isUpper(char);
int numJewelsInStones(char* jewels, char* stones) {
	int count = 0, jLen = strlen(jewels), sLen = strlen(stones);
	bool* hashMap = (bool*)calloc(HASH_SIZE, sizeof(bool));
	char temp;
	for (int i = 0; i < jLen; i++) {
		temp = jewels[i];
		hashMap[isUpper(temp) ? temp - UPPER_LETTER : temp - LOWER_LETTER] = true;
	}
	for (int i = 0; i < sLen; i++) {
		if (hashMap[isUpper ? temp - UPPER_LETTER : temp - LOWER_LETTER])
			count++;
	}
	return count;
}
bool isUpper(char c) {
	return 'A' <= c && c <= 'Z';
}