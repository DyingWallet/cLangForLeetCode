//给你一份工作时间表hours，上面记录着某一位员工每天的工作小时数。
//我们认为当员工一天中的工作小时数大于8 小时的时候，那么这一天就是「劳累的一天」。
//所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
//请你返回「表现良好时间段」的最大长度。
//示例 1：
//输入：hours = [9, 9, 6, 0, 6, 6, 9]
//输出：3
//解释：最长的表现良好时间段是[9, 9, 6]。
//提示：
//1 <= hours.length <= 10000
//0 <= hours[i] <= 16
//贪心
#include"leetCode.h"

int longestWPI(int* hours, int hoursSize) {
	int res = 0, count = 0, tired = 0, i = 0, total = 0;
	while (i < hoursSize) {
		if (hours[i] > 8) {
			tired++;
			count++;
			total++;
		} else if (hours[i] <= 8 && tired > 0) {// hours[i] <= 8
			if (tired == 1) {
				res = res < count ? count : res;
				count = 0;
			} else count++;
			tired--;
		}
		i++;
		if (total > i / 2) res = i;
	}
	return res;
}