class Solution {
public:
	void replaceSpace(char *str, int length) {
		vector<int> a;
		for (int i = 0; i < length; i++) {
			if (' ' == *(str + i)) {
				a.push_back(i);
			}
		}
		int newLen = length + a.size() * 2;
		a.push_back(length);
		char* newStr = str + newLen;
		int size;
		for (int j = (a.size() - 2); j >= 0; j--) {
			size = a[j + 1] - a[j] - 1;	//移动数据长度
			this->memmove(newStr - size, str + a[j] + 1, size);
			newStr -= size;
			this->memmove(newStr - 3, "%20", 3);
			newStr -= 3;
		}
	}

	void memmove(char* dst, char* src, int size) {
		for (int i = size-1; i>=0; i--) {
			*(dst + i) = *(src + i);
			//cout << *(src + i) << endl;
		}
		//cout << "----" << endl;
	}
};