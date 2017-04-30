class Solution {
public:
    //1.令两个只出现一次的数为a,b，如果a+b为奇数，则总和为奇数,如果a+b为偶数,则总和为偶数,为什么没有联想到应用于每一位？？？
    //2.得到他人提示关键词“异或”，发现条件1应用于每一bit则成立：所有数异或等于a异或b，如只有一个数，则所有数异或等于该数
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int a=0,c=0,d=0;
        unsigned int b=1;
        vector<int>::iterator iter;
        for(iter=data.begin();iter!=data.end();iter++){
            a=a^(*iter);
        }
        while((a&b)==0){	//两数不同，不可能每位都相同
        	b=b<<1;
        }
        for(iter=data.begin();iter!=data.end();iter++){
            if(*iter & b){	//不等于0的,一个num属于这里面
               c=c^*iter; 
            } else {	//等于0的，另一个num属于此中
               d=d^*iter;
            }
        }
        for(iter=data.begin();iter!=data.end();iter++){
            if(*iter==c){
                *num1=*iter;
            }
            if(*iter==d){
                *num2=*iter;
            }
        }
    }

};