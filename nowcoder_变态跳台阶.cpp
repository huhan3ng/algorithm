#include<math.h>
class Solution {	//组合数学n个桩划分划分成任意份，2的n-1次
public:
    int jumpFloorII(int number) {
		return pow(2, number-1);
    }
};