//给你两个二进制字符串，返回它们的和（用二进制表示）。
//输入为 非空 字符串且只包含数字1和0。
//示例1:
//输入: a = "11", b = "1"
//输出 : "100"
//示例2 :
//输入 : a = "1010", b = "1011"
//输出 : "10101"
#include"leetCode.h"
static char map[2] = { '0','1' };//数据字典
char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1, j = strlen(b) - 1, k = i > j ? i + 1 : j + 1;
    char* res = (char*)calloc(k + 2, sizeof(char));//k+2是为了给可能的最高位进位与'\0'留出空间
    int isUp = 0, temp = 0;//进位flag与二进制的整形计算值
    for (; i >= 0 && j >= 0; i--, j--) {//计算等长部分
        temp = a[i] - '0' + b[j] - '0' + isUp;
        isUp = temp / 2;
        if (isUp)temp %= 2;
        res[k--] = map[temp];
    }
    if (i < 0 && j >= 0) {//b串更长
        for (; j >= 0; j--) {
            temp = b[j] - '0' + isUp;
            isUp = temp / 2;
            if (isUp) temp %= 2;
            res[k--] = map[temp];
        }
    } else if (i >= 0 && j < 0) {//a串更长
        for (; i >= 0; i--) {
            temp = a[i] - '0' + isUp;
            isUp = temp / 2;
            if (isUp) temp %= 2;
            res[k--] = map[temp];
        }
    }
    if (isUp) {//处理最高位进位
        res[k--] = map[1];
        return res;
    }
    return res + 1;//若计算最后最高位不进位，指针后移一个char的距离，避开calloc初始化时插入的'\0'并返回结果
}