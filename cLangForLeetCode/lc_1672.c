//给你一个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i 位客户在第 j 家银行托管的资产数量。返回最富有客户所拥有的 资产总量 。
//客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。
//示例 1：
//输入：accounts = [[1, 2, 3], [3, 2, 1]]
//输出：6
//解释：
//第 1 位客户的资产总量 = 1 + 2 + 3 = 6
//第 2 位客户的资产总量 = 3 + 2 + 1 = 6
//两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。

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