//�������һ�����Խ����ַ��� command �� Goal ������ ��command �� "G"��"()" �� / �� "(al)" ��ĳ��˳����ɡ�
//Goal �������Ὣ "G" ����Ϊ�ַ��� "G"��"()" ����Ϊ�ַ��� "o" ��"(al)" ����Ϊ�ַ��� "al" ��
//Ȼ�󣬰�ԭ˳�򽫾����͵õ����ַ������ӳ�һ���ַ�����
//�����ַ��� command ������ Goal ������ �� command �Ľ��ͽ����
//ʾ�� 1��
//���룺command = "G()(al)"
//�����"Goal"
//���ͣ�Goal ��������������Ĳ���������ʾ��
//G->G
//()->o
//(al)->al
//������ӵõ��Ľ���� "Goal"
//ʾ�� 2��
//���룺command = "G()()()()(al)"
//�����"Gooooal"
//ʾ�� 3��
//���룺command = "(al)G(al)()()G"
//�����"alGalooG"
#include"leetCode.h"

char* interpret(char* command) {
	int i = 0, pre = 0, cur = 1;
	char* res = (char*)calloc(strlen(command) + 1, sizeof(char));
	while (command[pre] != '\0') {
		if (command[pre] == 'G') {
			res[i++] = 'G';
			pre++, cur++;
		} else if (command[pre] == '(' && command[cur] == ')') {
			res[i++] = 'o';
			pre += 2, cur += 2;
		} else {
			res[i++] = 'a';
			res[i++] = 'l';
			pre += 4, cur += 4;
		}
	}
	return res;
}