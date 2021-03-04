//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ����е�֧�ֵ����в�����push��pop��peek��empty����
//ʵ�� MyQueue �ࣺ
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false
//˵����
//��ֻ��ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ��?push to top, peek / pop from top, size, ��?is empty?�����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//���ף�
//���ܷ�ʵ��ÿ��������̯ʱ�临�Ӷ�Ϊ O(1) �Ķ��У����仰˵��ִ�� n ����������ʱ�临�Ӷ�Ϊ O(n) ����ʹ����һ���������ܻ��ѽϳ�ʱ�䡣
#include"leetCode.h"

typedef struct {
	int val;
	struct StackNode* next;
}StackNode;

typedef struct {
	StackNode* top;
	int stackSize;
}Stack;

typedef struct {
	Stack* inStack;
	Stack* outStack;
	int queueSize;
} MyQueue;

Stack* init();
int peek(Stack*);
StackNode* pop(Stack*);
void push(Stack*, int);
void clear(Stack*);
bool isEmpty(Stack*);

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* queue = NULL;
	if ((queue = (MyQueue*)malloc(sizeof(MyQueue))) != NULL) {
		queue->inStack = init();
		queue->outStack = init();
		queue->queueSize = 0;
		return queue;
	}
	return NULL;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	push(obj->inStack, x);
	obj->queueSize++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (isEmpty(obj->outStack)) {
		if (isEmpty(obj->inStack)) return 0;
		while (!isEmpty(obj->inStack))
			push(obj->outStack, pop(obj->inStack)->val);
	}
	obj->queueSize--;
	return pop(obj->outStack)->val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (isEmpty(obj->outStack)) {
		if (isEmpty(obj->inStack)) return 0;
		while (!isEmpty(obj->inStack))
			push(obj->outStack, pop(obj->inStack)->val);
	}
	return peek(obj->outStack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return obj->queueSize == 0;
}

void myQueueFree(MyQueue* obj) {
	if (!obj->queueSize) {
		clear(obj->inStack);
		clear(obj->outStack);
	}
}

//stack Operation

Stack* init() {
	Stack* stack = NULL;
	if ((stack = (Stack*)malloc(sizeof(Stack))) != NULL) {
		stack->stackSize = 0;
		stack->top = NULL;
		return stack;
	}
	return NULL;
}

int peek(Stack* stack) {
	if (stack->stackSize)
		return stack->top->val;
	return 0;
}

StackNode* pop(Stack* stack) {
	if (stack->stackSize) {
		StackNode* temp = NULL;
		temp = stack->top;
		stack->top = temp->next;
		stack->stackSize--;
		return temp;
	}
	return NULL;
}

void push(Stack* stack, int val) {
	StackNode* node = NULL;
	if ((node = (StackNode*)malloc(sizeof(StackNode))) == NULL) return;
	if (stack->stackSize)
		node->next = stack->top;
	node->val = val;
	stack->top = node;
	stack->stackSize++;
}

void clear(Stack* stack) {
	while (stack->stackSize) {
		pop(stack);
	}
	stack->top = NULL;
}

bool isEmpty(Stack* stack) {
	return stack->stackSize == 0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/