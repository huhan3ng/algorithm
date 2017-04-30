class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		int sx = array.size() - 1, sy = 0;
		while (sx>=0 && sy<array[0].size()) {
			if (target < array[sx][sy]) {
				sx--;
			}
			else if(target > array[sx][sy]){
				sy++;
			}
			else {
				return true;
			}
		}
		return false;
	}
};