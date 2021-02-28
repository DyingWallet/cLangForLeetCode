//�����ַ���J?����ʯͷ�б�ʯ�����ͣ����ַ���S������ӵ�е�ʯͷ��
//S��ÿ���ַ�������һ����ӵ�е�ʯͷ�����ͣ�����֪����ӵ�е�ʯͷ���ж����Ǳ�ʯ��
//J?�е���ĸ���ظ���J��S�е������ַ�������ĸ����ĸ���ִ�Сд�����"a"��"A"�ǲ�ͬ���͵�ʯͷ��
//ʾ�� 1:
//����: J = "aA", S = "aAAbbbb"
//��� : 3
//ʾ�� 2 :
//���� : J = "z", S = "ZZ"
//��� : 0
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