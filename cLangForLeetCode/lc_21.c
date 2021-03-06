//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//示例 1：
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]
//示例 2：
//输入：l1 = [], l2 = []
//输出：[]
//示例 3：
//输入：l1 = [], l2 = [0]
//输出：[0]
//提示：
//两个链表的节点数目范围是[0, 50]
//- 100 <= Node.val <= 100
//l1 和 l2 均按 非递减顺序 排列

#include"leetCode.h"

//迭代方式
typedef struct ListNode listNode;
listNode* append(listNode** cur, listNode* node);
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (!l1 || !l2) return l1 == NULL ? l2 : l1;//判空
	listNode* res = (listNode*)calloc(1, sizeof(listNode)), * pre = res;
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			l1 = append(&pre, l1);
		} else {
			l2 = append(&pre, l2);
		}
	}
	if (!l1) pre->next = l2;
	if (!l2) pre->next = l1;
	return res->next;
}

listNode* append(listNode** pre, listNode* node) {
	listNode* temp = node->next;
	(*pre)->next = node;
	node->next = NULL;
	*pre = (*pre)->next;
	return temp;
}