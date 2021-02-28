//输入：items = [["phone", "blue", "pixel"], ["computer", "silver", "lenovo"], ["phone", "gold", "iphone"]], ruleKey = "color", ruleValue = "silver"
//输出：1
//解释：只有一件物品匹配检索规则，这件物品是["computer", "silver", "lenovo"] 。
#include"leetCode.h"

bool strcmp_my(char* str1, char* str2);

int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue) {
	char** item = NULL;
	int type = -1;
	int counter = 0;
	if (strcmp_my("type", ruleKey)) {
		type = 0;
	}
	else if (strcmp_my("color", ruleKey)) {
		type = 1;
	}
	else if (strcmp_my("name", ruleKey)) {
		type = 2;
	}

	for (int i = 0; i < itemsSize; i++) {
		item = *(items + i);
		if (strcmp_my(item[type], ruleValue))
			counter++;
	}
	return counter;
}

bool strcmp_my(char* str1, char* str2) {
	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}