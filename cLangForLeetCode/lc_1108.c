//����һ����Ч�� IPv4 ��ַaddress��������� IP ��ַ����Ч���汾��
//��ν��Ч��IP ��ַ����ʵ������"[.]"������ÿ�� "."��
//ʾ�� 1��
//���룺address = "1.1.1.1"
//�����"1[.]1[.]1[.]1"
//ʾ�� 2��
//���룺address = "255.100.50.0"
//�����"255[.]100[.]50[.]0"

#include"leetCode.h"

char* defangIPaddr(char* address) {
	int len = strlen(address), i = 0, j = 0;
	char* res = (char*)calloc(len + 7, sizeof(char));
	if (address != NULL && res != NULL) {
		while (address[i] != '\0') {
			res[j++] = address[i++];
			if (address[i] == '.') {
				res[j++] = '[';
				res[j++] = address[i++];
				res[j++] = ']';
			}
		}
		return res;
	}
	exit(-1);
}