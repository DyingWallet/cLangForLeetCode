//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。
//现有一个链表head = [4, 5, 1, 9]，它可以表示为:
//示例 1：
//输入：head = [4, 5, 1, 9], node = 5
//输出：[4, 1, 9]
//解释：给定你链表中值为5的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
//示例 2：
//输入：head = [4, 5, 1, 9], node = 1
//输出：[4, 5, 9]
//解释：给定你链表中值为?1?的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

#include"leetCode.h"

typedef struct ListNode* listNode;

void deleteNode_2(struct ListNode* node) {
	listNode temp = node->next;
	node->val = temp->val;
	node->next = temp->next;
	node = temp;
}