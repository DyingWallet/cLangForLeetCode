//����һ��haystack �ַ�����һ�� needle �ַ�����
//�� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ��(��0��ʼ)��
//��������ڣ��򷵻� - 1��
//ʾ�� 1:
//����: haystack = "hello", needle = "ll"
//��� : 2
//ʾ�� 2 :
//���� : haystack = "aaaaa", needle = "bba"
//��� : -1
//˵�� :
//��needle�ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣
//���ڱ�����ԣ���needle�ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե�strstr()�Լ� Java��indexOf()���������
#include"leetCode.h"
int strStr(char* haystack, char* needle) {
	int hLen = strlen(haystack), nLen = strlen(needle), i = -1;
	if (hLen == 0 && nLen == 0) return 0;
	while (++i <= (hLen - nLen)) {
		int j = 0, k = i;
		while (needle[j] != '\0') {
			if (needle[j] != haystack[k++])	break;
			j++;
		}
		if (needle[j] == '\0') return i;
	}
	return -1;
}