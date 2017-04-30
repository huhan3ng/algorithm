class Solution {
public:
    //提交通过立马查看排名，如果性能没问题的话一般都是第一，然而并不是，一定有性能更优的解法
    //反证法，从终结状态往初始状态推导，每一步都有两个关键条件，1.倒数第n-1个位置经过m个小朋友后到达倒数第n个，且剩余可选小朋友共有n+1个
    //如： 初始状态只有 i1, 之后插入i2, 插入i3时有两个可选位置，i1,i2之间和 i2右边,代入m可得到唯一合法的位置
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1){
            return -1;
        }
        int p=0;
        for(int i=1;i<n;i++){
            p=(((p-m)%i+i)%i+1)%(i+1);
        }
        return ((m-1)%n-p+n)%n;
    }
};