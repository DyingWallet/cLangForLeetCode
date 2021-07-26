#include"leetCode.h"
#include"leetCodeStructs.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode listNode;

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	int lenA = 0, lenB = 0, len = 0;
	listNode* ha = headA, * hb = headB;

	//统计长度
	while (ha || hb) {
		lenA += ha ? 1 : 0;
		lenB += hb ? 1 : 0;
		ha = ha ? ha->next : NULL;
		hb = hb ? hb->next : NULL;
	}
	//长度差值
	len = abs(lenA - lenB);
	ha = lenA >= lenB ? headA : headB;
	hb = lenA >= lenB ? headB : headA;

	for (int i = 0; i < len; i++)
		ha = ha->next;

	while (ha && hb) {
		if (ha == hb) return ha;
		ha = ha->next;
		hb = hb->next;
	}
	return NULL;
}