//СA �� СB ��������֡�СB ÿ�δ� 1, 2, 3 �����ѡ��һ����СA ÿ��Ҳ�� 1, 2, 3 ��ѡ��һ���¡�
//����һ���������������Ϸ���뷵�� СA �¶��˼��Σ�
//�����guess����Ϊ СA ÿ�εĲ²⣬answer����Ϊ СB ÿ�ε�ѡ��guess��answer�ĳ��ȶ�����3��
//ʾ�� 1��
//���룺guess = [1, 2, 3], answer = [1, 2, 3]
//�����3
//���ͣ�СA ÿ�ζ��¶��ˡ�
//ʾ�� 2��
//���룺guess = [2, 2, 3], answer = [3, 2, 1]
//�����1
//���ͣ�СA ֻ�¶��˵ڶ��Ρ�

#include"leetCode.h"

int game(int* guess, int guessSize, int* answer, int answerSize) {
	int res = 0;

	for (int i = 0; i < guessSize; i++) {
		res += guess[i] == answer[i] ? 1 : 0;
	}
	return res;
}