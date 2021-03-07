//����һ�������� n �����������еĵ� n �
//��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
//����Խ����������ɵݹ鹫ʽ����������ַ������У�
//countAndSay(1) = "1"
//countAndSay(n) �Ƕ� countAndSay(n - 1) ��������Ȼ��ת������һ�������ַ�����
//ǰ�������£�
//1.     1			��һ�������� 1
//2.     11			����ǰһ�������� 1 �� �� һ �� 1 �������� "11"
//3.     21			����ǰһ�������� 11 �� �� �� �� 1 �� ������ "21"
//4.     1211		����ǰһ�������� 21 �� �� һ �� 2 + һ �� 1 �� ������ "1211"
//5.     111221		����ǰһ�������� 1211 �� �� һ �� 1 + һ �� 2 + �� �� 1 �� ������ "111221"
//6.	 312211		7.		13112221		8.1113213211		9.31131211131221
//Ҫ����һ�������ַ���������Ҫ���ַ����ָ�Ϊ��С�������飬ÿ���鶼����������� ��ͬ�ַ� ��ɡ�
//Ȼ�����ÿ���飬�������ַ���������Ȼ�������ַ����γ�һ�������顣
//Ҫ������ת��Ϊ�����ַ������Ƚ�ÿ���е��ַ������������滻���ٽ���������������������
//��ʾ��
//1 <= n <= 30
#include"leetCode.h"
char* counter(int n, int* returnSize);
char* countAndSay(int n) {
	int returnSize = 0;
	return counter(n, &returnSize);
}

char* counter(int n, int* returnSize) {
	if (n == 1) {
		*returnSize = 1;
		return "1";
	} else {
		char* rtnStr = counter(n - 1, returnSize);
		char* res = (char*)calloc(2 * (*returnSize) + 1, sizeof(char));
		char pre = rtnStr[0], cur;
		int i = -1, j = 0, count = 0;
		while (++i <= *returnSize) {
			cur = rtnStr[i];
			if (cur == pre)
				count++;
			else {
				res[j++] = count + '0';
				res[j++] = pre;
				if (cur == '\0') break;
				pre = cur;
				count = 1;	//��Ϊ1����0����ΪֻҪ����ĩβ����ǰ�������ٳ���һ��
			}
		}
		*returnSize = strlen(res);
		return res;
	}
}