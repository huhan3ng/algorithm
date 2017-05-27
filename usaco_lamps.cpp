/*
ID: huhan3n1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

unsigned long data[2] = {0};	//由两个long型来表示最多100位的集合
unsigned long mask_on[2] = {0};	//最终为打开装状态的掩码
unsigned long mask_off[2] = {0};//最终为关闭状态的掩码
unsigned long sorted_datas[200];//排序的结果集
int sorted_len;
int N,C;	//原数据集大小，操作次数
int OPER_NUM = 4;
unsigned long oper[8] = {
	0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF,	//操作1.取反
	0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA,	//操作2.奇数位取反，摩二加
	0x5555555555555555, 0x5555555555555555,	//操作3.偶数位取反
	0x9249924992499249, 0x9249924992499249	//操作4. 3×k+1 取反
	};

void insert_sort(long v1, long v2){	//对data作插入排序
	int i, j;
	for(i=0;i<sorted_len;i+=2){
		if(v1>sorted_datas[i] || (v1==sorted_datas[i] && v2>sorted_datas[i+1])){	//从小到大排序
			break;
		}
	}
	for(j=sorted_len-1;j>=i;j-=2){	//把当前到最后的都往后挪两个
		sorted_datas[i+2]=sorted_datas[i];
	}
	sorted_datas[i]=v1;
	sorted_datas[i+1]=v2;
}

void subs(int offset, int len){
	if(len==0){	//选完组合了
		insert_sort(data[0], data[1]);
	} else{
		for(int i=offset+1;i<(OPER_NUM-len);i++){
			data[0] ^= oper[2*i];
			data[1] ^= oper[2*i+1];
			subs(i, len-1);
			data[0] ^= oper[2*i];
			data[1] ^= oper[2*i+1];
		}
	}
}

int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
	fin>>N>>C;
	int t=0;
	while(t!=-1){	//构造掩码 on
		fin>>t;
		if(t<64){
			mask_on[0] = mask_on[0] | ((long)1)<<(t-1);
		} else {
			mask_on[0] = mask_on[0] | ((long)1)<<(t-64);
		}
	}
	while(t!=-1){	//构造掩码 off
		fin>>t;
		if(t<64){
			mask_off[0] = mask_off[0] | ((long)1)<<(t-1);
		} else {
			mask_off[0] = mask_off[0] | ((long)1)<<(t-64);
		}
	}
	while(C>0){
		if(C<=4){
			subs(0, C);
		}
		C-=2;
	}
	
    return 0;
}