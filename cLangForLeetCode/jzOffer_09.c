//������ջʵ��һ�����С�
//���е��������£���ʵ��������������appendTail��deleteHead��
//�ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�
//(��������û��Ԫ�أ�deleteHead�������� - 1)
//ʾ�� 1:
//���룺
//["CQueue", "appendTail", "deleteHead", "deleteHead"]
//[[], [3], [], []]
//�����[null, null, 3, -1]
//ʾ�� 2��
//���룺
//["CQueue", "deleteHead", "appendTail", "appendTail", "deleteHead", "deleteHead"]
//[[], [], [5], [2], [], []]
//�����[null, -1, null, null, 5, 2]

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