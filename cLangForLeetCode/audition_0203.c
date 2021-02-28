/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode listNode;

void deleteNode(struct ListNode* node) {
	listNode* temp = node->next;
	node->val = temp->val;
	node->next = temp->next;
	node = temp;
}