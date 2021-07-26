#include"leetCode.h"
#include"leetCodeStructs.h"

typedef struct StackNode MinStackNode;
struct StackNode{
	int val;
	MinStackNode* next;
};

typedef struct Stack MinStack;
struct Stack {
	MinStackNode* top;
	MinStackNode* minNode;
	int size;
};


/** initialize your data structure here. */

MinStack* minStackCreate() {
	return (MinStack*)calloc(1, sizeof(MinStack));
}

void minStackPush(MinStack* obj, int val) {
	MinStackNode* node = (MinStackNode*)calloc(1, sizeof(MinStackNode));
	node->val = val;

	if (obj->top == NULL)//空栈
		obj->minNode = node;
	else //非空栈
		obj->minNode = node->val < obj->minNode->val ? node : obj->minNode;

	node->next = obj->top;
	obj->top = node;
	obj->size++;
}

void minStackPop(MinStack* obj) {
	if (obj->size) {
		obj->top = obj->top->next;
		obj->size--;
		obj->minNode = obj->top;
		MinStackNode* tmp = obj->top;
		//维护最小值指针
		while (tmp) {
			if (obj->minNode->val > tmp->val)
				obj->minNode = tmp;
			tmp = tmp->next;
		}
	}
}

int minStackTop(MinStack* obj) {
	if (obj->size)
		return obj->top->val;
	return NULL;
}

int minStackGetMin(MinStack* obj) {
	if (obj->size)
		return obj->minNode->val;
	return NULL;
}

void minStackFree(MinStack* obj) {
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/