//给你一个有效的 IPv4 地址address，返回这个 IP 地址的无效化版本。
//所谓无效化IP 地址，其实就是用"[.]"代替了每个 "."。
//示例 1：
//输入：address = "1.1.1.1"
//输出："1[.]1[.]1[.]1"
//示例 2：
//输入：address = "255.100.50.0"
//输出："255[.]100[.]50[.]0"

#include"leetCode.h"

char* defangIPaddr(char* address) {
	int len = strlen(address), i = 0, j = 0;
	char* res = (char*)calloc(len + 7, sizeof(char));
	if (address != NULL && res != NULL) {
		while (address[i] != '\0') {
			res[j++] = address[i++];
			if (address[i] == '.') {
				res[j++] = '[';
				res[j++] = address[i++];
				res[j++] = ']';
			}
		}
		return res;
	}
	exit(-1);
}