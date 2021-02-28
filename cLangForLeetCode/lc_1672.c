//����һ�� m x n ���������� accounts ������ accounts[i][j] �ǵ� i λ�ͻ��ڵ� j �������йܵ��ʲ�������������пͻ���ӵ�е� �ʲ����� ��
//�ͻ��� �ʲ����� ���������ڸ��������йܵ��ʲ�����֮�͡���пͻ����� �ʲ����� ���Ŀͻ���
//ʾ�� 1��
//���룺accounts = [[1, 2, 3], [3, 2, 1]]
//�����6
//���ͣ�
//�� 1 λ�ͻ����ʲ����� = 1 + 2 + 3 = 6
//�� 2 λ�ͻ����ʲ����� = 3 + 2 + 1 = 6
//��λ�ͻ�������еģ��ʲ��������� 6 �����Է��� 6 ��

#define Minimal -10e9
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
	int maxWealth = Minimal;
	int sum;
	for (int i = 0; i < accountsSize; i++) {
		sum = 0;
		for (int j = 0; j < *accountsColSize; j++) {
			sum += accounts[i][j];
		}
		maxWealth = maxWealth > sum ? maxWealth : sum;
	}
	return maxWealth;
}