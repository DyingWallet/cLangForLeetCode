//����һ�ݹ���ʱ���hours�������¼��ĳһλԱ��ÿ��Ĺ���Сʱ����
//������Ϊ��Ա��һ���еĹ���Сʱ������8 Сʱ��ʱ����ô��һ����ǡ����۵�һ�졹��
//��ν���������õ�ʱ��Ρ�����ζ�����ʱ���ڣ������۵����������ϸ� ���ڡ������۵���������
//���㷵�ء���������ʱ��Ρ�����󳤶ȡ�
//ʾ�� 1��
//���룺hours = [9, 9, 6, 0, 6, 6, 9]
//�����3
//���ͣ���ı�������ʱ�����[9, 9, 6]��
//��ʾ��
//1 <= hours.length <= 10000
//0 <= hours[i] <= 16
//̰��
#include"leetCode.h"

int longestWPI(int* hours, int hoursSize) {
	int res = 0, count = 0, tired = 0, i = 0, total = 0;
	while (i < hoursSize) {
		if (hours[i] > 8) {
			tired++;
			count++;
			total++;
		} else if (hours[i] <= 8 && tired > 0) {// hours[i] <= 8
			if (tired == 1) {
				res = res < count ? count : res;
				count = 0;
			} else count++;
			tired--;
		}
		i++;
		if (total > i / 2) res = i;
	}
	return res;
}