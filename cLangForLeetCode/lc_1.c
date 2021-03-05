//1. ����֮��
//����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
//����԰�����˳�򷵻ش𰸡�
//ʾ�� 1��
//���룺nums = [2, 7, 11, 15], target = 9
//�����[0, 1]
//���ͣ���Ϊ nums[0] + nums[1] == 9 ������[0, 1] ��
//ʾ�� 2��
//���룺nums = [3, 2, 4], target = 6
//�����[1, 2]
//ʾ�� 3��
//���룺nums = [3, 3], target = 6
//�����[0, 1]
//��ʾ��
//2 <= nums.length <= 10e3
//- 10e9 <= nums[i] <= 10e9
//- 10e9 <= target <= 10e9
//ֻ�����һ����Ч��
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"leetCode.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	int* res = (int*)calloc(*returnSize, sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				res[0] = i;
				res[1] = j;
			}
		}
	}
	return res;
}