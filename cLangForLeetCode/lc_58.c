//����һ���ַ��� s�������ɵ�����ɣ�����֮���ÿո������
//�����ַ��������һ�����ʵĳ��ȡ�������������һ�����ʣ��뷵�� 0��
//���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����
//ʾ�� 1��
//���룺s = "Hello World"
//�����5
//ʾ�� 2��
//���룺s = " "
//�����0
//��ʾ��
//1 <= s.length <= 104
//s ����Ӣ����ĸ�Ϳո� ' ' ���
#include"leetCode.h"

int lengthOfLastWord(char* s) {
	bool isWord = false;
	int len = strlen(s), res = 0, i = len;
	while (--i>=0) {
		if (s[i] != ' ') {
			res++;
			isWord = true;
		}
		if (s[i] == ' ' && isWord) break;
	}
	return res;
}