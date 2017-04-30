class Solution {
    vector<int> tmp;
public:
    int InversePairs(vector<int> data) {
     	//1.遍历~O(n*n)  ----超时
        //2.从左往右计算，同时将左边排序，右边利用二分查找插入，如果复制内存时间固定的话，时间复杂度~O（n*lgn),但是需要内存拷贝(insert)，感觉不如1 ---超时
        //3.在2的基础上优化，由于2中每次insert的时间不是O(1),而是O(n),所以总复杂度仍然是O(n*n)
        //	由n-1~1的划分改为 n/2~n/2的划分，由左往右合并，左小右大，对右边元素计算左边比他大的个数 ----超时，干他娘,fuccccccccccck
        // 1000000007 作用为通过大质数保证结果很大时也能通过返回值正确判断，如果是很大的非质数，则有可能返回值是不正确的但是刚好取模之后是正确的
        //3运行时间 220ms， 尝试把动态创建和插入数组优化为预先申请好定长数组
        tmp.resize(200000);
        return mergeSort(data, 0, data.size());
    }
    
    int mergeSort(vector<int> &data, int h, int t){
        if((t-h)<=1){
            return 0;
        }
        else{
            int x1=mergeSort(data, h, (h+t)/2);
            int x2=mergeSort(data, (h+t)/2, t);
            int x3=merge(data, h, (h+t)/2, t);
            return (x1+x2+x3)%1000000007;
        }
    }
    
    int merge(vector<int> &data, int h, int c, int t){
        int i1=h,i2=c,i3=h,num=0;
        while(i1<c && i2<t){
            if(data[i1]>data[i2]){
                tmp[i3]=data[i2];
                num=(num+(i2-i3))%1000000007;
                i2++;
                i3++;
            } else {
                tmp[i3++]=data[i1];
                i1++;
            }
        }
        if(i1==c){
            for(;i2<t;i2++){
                tmp[i3++]=data[i2];
            }
        }
        if(i2==t){
            for(;i1<c;i1++){
                tmp[i3++]=data[i1];
            }
        }
        //拷贝回去
        for(int i=h;i<t;i++){
            data[i]=tmp[i];
        }
        return num;
    }
    
};