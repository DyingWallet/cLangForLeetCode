//用两个栈实现一个队列。
//队列的声明如下，请实现它的两个函数appendTail和deleteHead，
//分别完成在队列尾部插入整数和在队列头部删除整数的功能。
//(若队列中没有元素，deleteHead操作返回 - 1)
//示例 1:
//输入：
//["CQueue", "appendTail", "deleteHead", "deleteHead"]
//[[], [3], [], []]
//输出：[null, null, 3, -1]
//示例 2：
//输入：
//["CQueue", "deleteHead", "appendTail", "appendTail", "deleteHead", "deleteHead"]
//[[], [], [5], [2], [], []]
//输出：[null, -1, null, null, 5, 2]

typedef struct {
	int i;
} CQueue;


CQueue* cQueueCreate() {

}

void cQueueAppendTail(CQueue* obj, int value) {

}

int cQueueDeleteHead(CQueue* obj) {

}

void cQueueFree(CQueue* obj) {

}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);

 * int param_2 = cQueueDeleteHead(obj);

 * cQueueFree(obj);
*/