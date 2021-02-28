//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//请定义一个函数实现字符串左旋转操作的功能。
//比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
//示例 1：
//输入 : s = "abcdefg", k = 2
//输出 : "cdefgab"
//示例 2：
//输入 : s = "lrloseumgh", k = 6
//输出 : "umghlrlose"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverseLeftWords(char* s, int n) {
	int i = 0, len = strlen(s);
	char* ans = (char*)malloc((len + 1) * sizeof(char));
	while (i < len)
		*(ans++) = s[(n + i++) % len];
	*ans = '\0';
	return ans - len;
}

//char* reverseLeftWords(char* s, int n) {
//	int i = 0, j = 0;
//	n %= strlen(s);
//	char* temp = NULL;
//	temp = (char*)malloc(n * sizeof(char));
//	if (temp == NULL)
//		exit(-1);
//	for (; s[i] != '\0'; i++) {
//		if (i < n)
//			*(temp + i) = s[i];
//		else
//			s[j++] = s[i];
//	}
//	for (i = 0; i < n; i++) {
//		s[j++] = *(temp + i);
//	}
//	s[j] = '\0';
//	return s;
//}