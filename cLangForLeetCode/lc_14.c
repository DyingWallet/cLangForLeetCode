//��дһ�������������ַ��������е������ǰ׺����������ڹ���ǰ׺�����ؿ��ַ���""��
//ʾ�� 1��
//���룺strs = ["flower", "flow", "flight"]
//�����"fl"
//ʾ�� 2��
//���룺strs = ["dog", "racecar", "car"]
//�����""
//���ͣ����벻���ڹ���ǰ׺��
//��ʾ��
//0 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] ����СдӢ����ĸ���
#include"leetCode.h"
char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0 || strs[0][0] == '\0') return "";	//�ַ��������������ݷ��ؿ�
	if (strsSize == 1) return strs[0];	//�ַ���������ֻ��һ���ַ�������������
	bool isEq = true;
	for (int j = 0;isEq; j++) {
		char c = strs[0][j];	//�Ե�һ���ַ�����ǰ׺��Ϊ��׼���бȽ�
		if (c == '\0')
			break;
		for (int i = 1; i < strsSize ; i++) {
			if (strs[i][j] != c) {
				isEq = false;
				strs[0][j] = '\0';
				break;
			}
		}
	}
	return strs[0];
}