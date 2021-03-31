//����һ�������ж��������Ƿ��л���
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
//��� pos �� - 1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
//��������д��ڻ����򷵻� true �� ���򣬷��� false ��
//���ף�
//������ O(1)�������������ڴ�����������
//ʾ�� 1��
//���룺head = [3, 2, 0, -4], pos = 1
//�����true
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
//ʾ��?2��
//���룺head = [1, 2], pos = 0
//�����true
//���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
//ʾ�� 3��
//���룺head = [1], pos = -1
//�����false
//���ͣ�������û�л���
//��ʾ��
//�����нڵ����Ŀ��Χ��[0, 104]
//- 105 <= Node.val <= 105
//pos Ϊ - 1 ���������е�һ�� ��Ч���� ��

#include"leetCode.h"

//����ָ��
typedef struct ListNode listNode;
bool hasCycle(struct ListNode* head) {
	if (!head || !head->next)
		return false;
	listNode* slow = head;
	listNode* fast = head->next;
	while (slow != fast) {
		if (fast == NULL || fast->next == NULL) return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}