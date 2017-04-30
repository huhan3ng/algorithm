class Solution {
public:
    int rectCover(int number) {
		//2*n矩形 高2宽n，如果第一根竖着，则方法为f(a-1)种,如果第一根横着
        //则必然有一根和第一根对齐组成2x2正方形，不妨设为第2根，方法为f(a-2)种
        //f(a)=f(a-1)+f(a-2)
        int f1=1,f2=2,f=0;
        if(number == 0){
          	return 0;  
        } else if(number==1){
            return f1; 
        } else if (number==2){
            return f2;
        }
        for(int i=3;i<=number;i++){
            f = f2;
            f2 = f1+f2;
            f1 = f;
        }
        return f2;
    }
};