//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
//�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
//���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
//ʾ�� 1��
//���� : s = "abcdefg", k = 2
//��� : "cdefgab"
//ʾ�� 2��
//���� : s = "lrloseumgh", k = 6
//��� : "umghlrlose"
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