//������Сд��ĸ��ɵ��ַ��� S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
//�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����
//����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��
//ʾ����
//���룺"abbaca"
//�����"ca"
//���ͣ�
//���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��
//֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"��
//��ʾ��
//1 <= S.length <= 20000
//S ����СдӢ����ĸ��ɡ�
#include"leetCode.h"


//ջ
char* removeDuplicates_1047(char* S) {
	int len = strlen(S);
	char* res = (char*)calloc(len+1, sizeof(char));
	int top = 0, i = 0;
	while (S[i] != '\0') {
		res[++top] = S[i];
		if (res[top - 1] == S[i])
			top -= 2;
		i++;
	}
	res[++top] = '\0';
	return res;
}


//�ݹ�

//char* removeDuplicates_1047(char* S) {
//	int len = strlen(S);
//	char next;
//	bool found = false;
//	int i = 0, j = 0;
//	while (S[i] != '\0') {
//		next = S[i + 1];
//		if (S[i] == next) {
//			i += 2;
//			found = true;
//		}
//		if(i<len)
//			S[j++] = S[i++];
//	}
//	S[j] = '\0';
//	if (found) return removeDuplicates_1047(S);
//	return S;
//}