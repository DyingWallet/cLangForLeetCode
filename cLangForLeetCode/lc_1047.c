//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
//示例：
//输入："abbaca"
//输出："ca"
//解释：
//例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
//之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
//提示：
//1 <= S.length <= 20000
//S 仅由小写英文字母组成。
#include"leetCode.h"


//栈
char* removeDuplicates_1047(char* S) {
	int len = strlen(S);
	char* res = (char*)calloc(len+1, sizeof(char));
	int top = 0, i = 0;
	while (S[i] != '\0') {
		res[++top] = S[i];
		if (res[top - 1] == S[i])
			top -= 2;
		i++;
	}
	res[++top] = '\0';
	return res;
}


//递归

//char* removeDuplicates_1047(char* S) {
//	int len = strlen(S);
//	char next;
//	bool found = false;
//	int i = 0, j = 0;
//	while (S[i] != '\0') {
//		next = S[i + 1];
//		if (S[i] == next) {
//			i += 2;
//			found = true;
//		}
//		if(i<len)
//			S[j++] = S[i++];
//	}
//	S[j] = '\0';
//	if (found) return removeDuplicates_1047(S);
//	return S;
//}