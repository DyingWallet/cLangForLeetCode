//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//示例 1:
//输入: "A man, a plan, a canal: Panama"
//输出 : true
//示例 2 :
//输入 : "race a car"
//输出 : false

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