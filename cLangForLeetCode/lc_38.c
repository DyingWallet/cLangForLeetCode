//给定一个正整数 n ，输出外观数列的第 n 项。
//「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
//你可以将其视作是由递归公式定义的数字字符串序列：
//countAndSay(1) = "1"
//countAndSay(n) 是对 countAndSay(n - 1) 的描述，然后转换成另一个数字字符串。
//前五项如下：
//1.     1			第一项是数字 1
//2.     11			描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
//3.     21			描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
//4.     1211		描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
//5.     111221		描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
//6.	 312211		7.		13112221		8.1113213211		9.31131211131221
//要描述一个数字字符串，首先要将字符串分割为最小数量的组，每个组都由连续的最多 相同字符 组成。
//然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。
//要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。
//提示：
//1 <= n <= 30
#include"leetCode.h"
char* counter(int n, int* returnSize);
char* countAndSay(int n) {
	int returnSize = 0;
	return counter(n, &returnSize);
}

char* counter(int n, int* returnSize) {
	if (n == 1) {
		*returnSize = 1;
		return "1";
	} else {
		char* rtnStr = counter(n - 1, returnSize);
		char* res = (char*)calloc(2 * (*returnSize) + 1, sizeof(char));
		char pre = rtnStr[0], cur;
		int i = -1, j = 0, count = 0;
		while (++i <= *returnSize) {
			cur = rtnStr[i];
			if (cur == pre)
				count++;
			else {
				res[j++] = count + '0';
				res[j++] = pre;
				if (cur == '\0') break;
				pre = cur;
				count = 1;	//设为1而非0是因为只要不是末尾，则当前数字至少出现一次
			}
		}
		*returnSize = strlen(res);
		return res;
	}
}