//����һ������ prices �����ĵ�i ��Ԫ��prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�
//��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ��
// ���һ���㷨�����������ܻ�ȡ���������
//��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��
//ʾ�� 1��
//���룺[7, 1, 5, 3, 6, 4]
//�����5
//���ͣ��ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6 - 1 = 5 ��
//ע���������� 7 - 1 = 6, ��Ϊ�����۸���Ҫ��������۸�ͬʱ���㲻��������ǰ������Ʊ��
//ʾ�� 2��
//���룺prices = [7, 6, 4, 3, 1]
//�����0
//���ͣ������������, û�н������, �����������Ϊ 0��
//��ʾ��
//1 <= prices.length <= 10e5
//0 <= prices[i] <= 10e4
#include"leetCode.h"

int maxProfit(int* prices, int pricesSize) {
	if (pricesSize == 1) return 0;
	int max = INT_MIN;
	int min = INT_MAX;
	int profit;

	for (int i = 0; i < pricesSize; i++) {
		min = min > prices[i] ? prices[i] : min;
		profit = prices[i] - min;
		max = max > profit ? max : profit;
	}
	return max <= 0 ? 0 : max;
}