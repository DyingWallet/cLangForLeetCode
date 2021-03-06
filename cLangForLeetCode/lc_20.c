//��һ��ֻ���� '('��')'��'{'��'}'��'['��']'���ַ��� s ���ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ʾ�� 1��			ʾ��2��
//���룺s = "()"		���룺s = "()[]{}"
//�����true			�����true
//ʾ��3��			ʾ��4��				ʾ��5��
//���룺s = "(]"		���룺s = "([)]"		���룺s = "{[]}"
//�����false		�����false			�����true

#include"leetCode.h"

bool isValid(char* s) {
	int len = strlen(s), i = 0, top = 0;
	if (len & 1) return false;
	char* stack = (char*)calloc(len + 2, sizeof(char));//len+2����Ϊstack[0]��װ�����Լ�������'\0'���ռ�
	//stack[0] = '-'; //����ʱ����
	while (i < len) {
		if (top != 0 && ((stack[top] == '(' && s[i] == ')') ||
			(stack[top] == '[' && s[i] == ']') ||
			(stack[top] == '{' && s[i] == '}'))) {//����ƥ��
			top--;
		} else
			stack[++top] = s[i];//��ջ
		i++;
	}
	return top == 0;
}