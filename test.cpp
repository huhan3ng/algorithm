//3,32,321

class Solution {
	vector<string> sNum;
public:
    string PrintMinNumber(vector<int> numbers) {
		//convert int to string
		for(int i=0;i<numbers.size();i++){
			sNum.push_back(num2str(numbers[i]));
		}
		//sNum 高位->低位,过滤重复的
		
    }
	
	void removeOther(){
		//去重
		for(int i=0;i<sNum.size();i++){
			if(!sNum[i].empty()){
				for(j=i;j<sNum.size();j++){
					if(sNum[i].compare(sNum[j])==0){
						sNum.erase(j);
					}
				}	
			}
		}
		//开始删除,先找到最小的，删除其余的
		int a,c;//c表第几位，从高位->地位
		while(sNum.size()>1){
			char min=sNum[0][0];
			for(int i=0;i<sNum.size();i++){
				if(c>=sNum.size()){
					a=sNum.[i][0];
				} else {
					a=sNum[i][c];
				}
				if(a<min){
					min = a;
				}
			}
			for(int i=0;i<sNum.size();i++){
				if(c>=sNum.size()){
					a=sNum.[i][0];
				} else {
					a=sNum[i][c];
				}
				if(a>min){
					sNum.erase[i];
				}
			}
			c++;	
		}
		
	}
	
	
	vector<char> num2str(int num){
		vector<char> ret;
		stack<char> tmp;
		do{
			tmp.push(num%10);
			num = num/10;
		}while(num>0)
		while(!tmp.empty()){
			ret.push_back(tmp.top());
			tmp.pop();
		}
		return ret;
	}
};