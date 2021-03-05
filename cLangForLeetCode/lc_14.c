//编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串""。
//示例 1：
//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//示例 2：
//输入：strs = ["dog", "racecar", "car"]
//输出：""
//解释：输入不存在公共前缀。
//提示：
//0 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] 仅由小写英文字母组成
#include"leetCode.h"
char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0 || strs[0][0] == '\0') return "";	//字符串数组中无数据返回空
	if (strsSize == 1) return strs[0];	//字符串数组中只有一个字符串，返回自身
	bool isEq = true;
	for (int j = 0;isEq; j++) {
		char c = strs[0][j];	//以第一个字符串的前缀作为基准进行比较
		if (c == '\0')
			break;
		for (int i = 1; i < strsSize ; i++) {
			if (strs[i][j] != c) {
				isEq = false;
				strs[0][j] = '\0';
				break;
			}
		}
	}
	return strs[0];
}