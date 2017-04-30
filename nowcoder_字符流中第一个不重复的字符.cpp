class Solution
{
public:
    char a[256]={0};//出现次数
    char b[256]={0};//初次出现位置
    char i=1;
  //Insert one char from stringstream
    void Insert(char ch)
    {
		a[ch]++;
        if(b[ch]==0){
            b[ch]=i;
        }
        i++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        unsigned minIndex=0xFFFFFF;
        int pos=0;
		for(int j=0;j<256;j++){
            if(a[j]==1 && b[j]<minIndex){
                minIndex=b[j];
                pos=j;
            }
        }
        if(pos==0){
            return '#';
        } else {
            return (char)pos;
        }
    }

};