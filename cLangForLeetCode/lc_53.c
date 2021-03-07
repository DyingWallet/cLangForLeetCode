//����һ���������� nums���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
//ʾ�� 1��											ʾ�� 3��
//���룺nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]		���룺nums = [0]
//�����6											�����0
//���ͣ�����������[4, -1, 2, 1] �ĺ����Ϊ6 ��		
//ʾ�� 2��											ʾ�� 4��
//���룺nums = [1]									���룺nums = [-1]
//�����1											����� - 1
//ʾ�� 5��
//���룺nums = [-100000]
//����� - 100000
//��ʾ��
//1 <= nums.length <= 3 * 10e4
//- 10e5 <= nums[i] <= 10e5
#include"leetCode.h"
//̰��
int maxSubArray(int* nums, int numsSize) {
	int res = INT_MIN, sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
		res = sum > res ? sum : res;
		if (sum <= 0) 	//�����sum����nums[i]��С��0�������ֱ����������i+i��ʼ�����ۼ�
			sum = 0;
	}
	return res;
}
//����+��������
//int maxSubArray(int* nums, int numsSize) {
//	int res = INT_MIN;
//	for (int i = 1; i <= numsSize;i++) {
//		int sum = 0;
//		for (int j = 0; j < i; j++) {
//			sum += nums[j];
//		}
//		res = res < sum ? sum : res;
//		for (int j = i; j < numsSize; j++) {//��������
//			sum = sum + nums[j] - nums[j-i];
//			res = res < sum ? sum : res;
//		}
//	}
//	return res;
//}