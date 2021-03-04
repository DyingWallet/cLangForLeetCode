//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//说明：
//你只能使用标准的栈操作 —— 也就是只有?push to top, peek / pop from top, size, 和?is empty?操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//进阶：
//你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
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