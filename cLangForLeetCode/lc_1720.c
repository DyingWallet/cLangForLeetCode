//δ֪ �������� arr �� n ���Ǹ�������ɡ�
//��������Ϊ����Ϊn-1����һ����������encoded������ encoded[i] = arr[i] XOR arr[i + 1]��
//���磬arr = [1, 0, 2, 1] �������õ� encoded = [1, 2, 3] ��
//������������� encoded ��ԭ���� arr �ĵ�һ��Ԫ�� first��arr[0]����
//����뷵��ԭ���� arr ������֤���𰸴��ڲ�����Ψһ�ġ�
//ʾ�� 1��
//���룺encoded = [1, 2, 3], first = 1
//�����[1, 0, 2, 1]
//���ͣ��� arr = [1, 0, 2, 1] ����ô first = 1 �� encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1, 2, 3]
//ʾ�� 2��
//���룺encoded = [6, 2, 7, 3], first = 4
//�����[4, 2, 0, 7, 4]
// xor == ^

#include"leetCode.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
	int* res = (int*)calloc(encodedSize + 1, sizeof(int));
	if (encodedSize > 0 && res != NULL) {
		int temp = first;
		res[0] = temp;
		for (int i = 0, j = 1; i < encodedSize; i++) {
			temp ^= encoded[i];
			res[j++] = temp;
		}
		*returnSize = encodedSize + 1;
		return res;
	}
	exit(-1);
}