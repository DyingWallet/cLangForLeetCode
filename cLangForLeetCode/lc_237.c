//���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㡣���뺯����Ψһ����Ϊ Ҫ��ɾ���Ľڵ� ��
//����һ������head = [4, 5, 1, 9]�������Ա�ʾΪ:
//ʾ�� 1��
//���룺head = [4, 5, 1, 9], node = 5
//�����[4, 1, 9]
//���ͣ�������������ֵΪ5�ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
//ʾ�� 2��
//���룺head = [4, 5, 1, 9], node = 1
//�����[4, 5, 9]
//���ͣ�������������ֵΪ?1?�ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.

#include"leetCode.h"

typedef struct ListNode* listNode;

void deleteNode_2(struct ListNode* node) {
	listNode temp = node->next;
	node->val = temp->val;
	node->next = temp->next;
	node = temp;
}