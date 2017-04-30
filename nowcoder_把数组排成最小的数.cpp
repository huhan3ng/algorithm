class Solution {
	public:
		string PrintMinNumber(vector<int> numbers) {
			int k,min;
			string ret;
			while(!numbers.empty()){
				min = 0;
				for(int i=1;i<numbers.size();i++){
					if(larger_equal(to_string(numbers[min]), to_string(numbers[i]))){
						min=i;
					}
				}
				ret.append(to_string(numbers[min]));
				numbers.erase(numbers.begin()+min);
			}
            return ret;
		}
		
		bool larger_equal(string s1, string s2){
			if(s1.compare(s2)==0){
				return true;
			} else {
				if(s1.length()<s2.length()){	//s1更短
					if(s2.compare(0, s1.length(), s1)<0){
						return true;
					} else if(s2.compare(0, s1.length(), s1)>0){
						return false;
					} else {
						return larger_equal(s1, s2.substr(s1.length()));
					}
				} else {	//s2更短
					if(s1.compare(0, s2.length(), s2)<0){
						return false;
					} else if(s1.compare(0, s2.length(), s2)>0){
						return true;
					} else {
						return larger_equal(s1.substr(s2.length()), s2);
					}
				}
			}
		}
    
        string to_string(int n){
            ostringstream stream;
            stream<<n;  //n为int类型
            return stream.str();
        }
		
};