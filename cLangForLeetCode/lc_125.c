//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//ʾ�� 1:
//����: "A man, a plan, a canal: Panama"
//��� : true
//ʾ�� 2 :
//���� : "race a car"
//��� : false

#include"leetCode.h"
//A:65 a:97 diff = a - A
#define DIF (int)('a'-'A')
bool isLetterNum(char*,int);
bool isPalindrome1(char* s) {
    int len = strlen(s);
    if (len <= 1) return true;
    int i = 0, j = 0;
    while (i < len) {
        if (isLetterNum(s, i)) {
            s[j++] = s[i];
            printf("%c\n", s[j - 1]);
        }
        i++;
    }
    int l = 0, r = j - 1;
    while (l < r)
        if (s[l++] != s[r--]) return false;

    return true;
}

bool isLetterNum(char* s, int index) {
    if ('A' <= s[index] && s[index] <= 'Z')
        s[index] += DIF;
    return ('a' <= s[index] && s[index] <= 'z') || ('0' <= s[index] && s[index] <= '9');
}