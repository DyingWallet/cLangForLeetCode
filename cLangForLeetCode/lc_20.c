//定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//示例 1：			示例2：
//输入：s = "()"		输入：s = "()[]{}"
//输出：true			输出：true
//示例3：			示例4：				示例5：
//输入：s = "(]"		输入：s = "([)]"		输入：s = "{[]}"
//输出：false		输出：false			输出：true

#include"leetCode.h"

bool isValid(char* s) {
	int len = strlen(s), i = 0, top = 0;
	if (len & 1) return false;
	char* stack = (char*)calloc(len + 2, sizeof(char));//len+2是因为stack[0]不装数据以及给最后的'\0'留空间
	//stack[0] = '-'; //调试时启用
	while (i < len) {
		if (top != 0 && ((stack[top] == '(' && s[i] == ')') ||
			(stack[top] == '[' && s[i] == ']') ||
			(stack[top] == '{' && s[i] == '}'))) {//存在匹配
			top--;
		} else
			stack[++top] = s[i];//入栈
		i++;
	}
	return top == 0;
}