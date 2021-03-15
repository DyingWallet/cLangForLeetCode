//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//示例1 :
//输入: 1->1->2
//输出 : 1->2
//示例2 :
//输入 : 1->1->2->3->3
//输出 : 1->2->3
#include"leetCode.h"

typedef struct ListNode listNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head || !head->next) return head;
	int temp = head->val;
	listNode* cur = head->next, * pre = head;
	while (cur) {
		if (pre->val == cur->val) {//存在相等值
			pre->next = cur->next;
			cur = pre->next;
		} else {//不相等
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}