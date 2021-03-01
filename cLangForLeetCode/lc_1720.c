//未知 整数数组 arr 由 n 个非负整数组成。
//经编码后变为长度为n-1的另一个整数数组encoded，其中 encoded[i] = arr[i] XOR arr[i + 1]。
//例如，arr = [1, 0, 2, 1] 经编码后得到 encoded = [1, 2, 3] 。
//给你编码后的数组 encoded 和原数组 arr 的第一个元素 first（arr[0]）。
//请解码返回原数组 arr 。可以证明答案存在并且是唯一的。
//示例 1：
//输入：encoded = [1, 2, 3], first = 1
//输出：[1, 0, 2, 1]
//解释：若 arr = [1, 0, 2, 1] ，那么 first = 1 且 encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1, 2, 3]
//示例 2：
//输入：encoded = [6, 2, 7, 3], first = 4
//输出：[4, 2, 0, 7, 4]
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