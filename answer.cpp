//3,32,321

class Solution {
	vector<string> sNum;
	public:
		string PrintMinNumber(vector<int> numbers) {
			int k;
			string ret;
			while(!numbers.empty()){
				min = 0;
				for(int i=1;i<numbers.size();i++){
					if(compare(to_string(numbers[i], numbers[min]))){
						min=i;
					}
				}
				ret.append(to_string(numbers[min]))
				numbers.erase(numbers.begin()+i);
			}
		}
		
		bool compare(string s1, string s2){
			if(s1.compare(s2)==0){
				return true;
			} else {
				if(s1.length()<s2.length()){	//s1更短
					if(s1.compare(0, s1.length(), s2)<0){
						return false;
					} else if(s1.compare(0, s1.length(), s2)>0){
						return true;
					} else {
						return this.compare(s1, s2.substr(s1.length()));
					}
				} else {
					if(s2.compare(0, s2.length(), s1)<0){
						return true;
					} else if(s2.compare(0, s2.length(), s1)>0){
						return false;
					} else {
						return this.compare(s1.substr(s2.length()), s2);
					}
				}
			}
		}
		
	
	
};