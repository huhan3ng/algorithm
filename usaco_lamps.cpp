/*
ID: huhan3n1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <iomanip>
using namespace std;

unsigned long data[2] = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};	//由两个long型来表示最多100位的集合
unsigned long mask_on[2] = {0};	//最终为打开装状态的掩码
unsigned long mask_off[2] = {0};//最终为关闭状态的掩码
unsigned long sorted_datas[200];//排序的结果集
int sorted_len=0;
int N,C;	//原数据集大小，操作次数
int OPER_NUM = 4;
unsigned long oper[8] = {
	0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF,	//操作1.取反
	0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA,	//操作2.奇数位取反，摩二加
	0x5555555555555555, 0x5555555555555555,	//操作3.偶数位取反
	0x4924924924924924, 0x9249249249249249	//操作4. 3×k+1 取反
	};

void binDump(long v1, long v2, int len, ofstream &fout){
	long x=1;
	long y=1;
	for(int i=0;i<len;i++){
		if(i>=64){
			if((v1&y)==0){
				cout<<"0";
			} else {
				cout<<"1";
			}
			y=y<<1;
		} else {
			if((v2&x)==0){
				fout<<"0";
			} else {
				fout<<"1";
			}
			x=x<<1;
		}
	}
	fout<<endl;
}
	
void hexDump(char* c, int len){
	for(int i=0;i<len;i++){
		printf("%02x", *(c+i) & 0xff);
	}
	cout<<endl;
}	

void dumpMask(){
	unsigned int *m1 = (unsigned int *)mask_on;
	cout<<"mask_on-----";
	printf("%08x", m1[0]);
	printf("%08x", m1[1]);
	printf("%08x", m1[2]);
	printf("%08x", m1[3]);
	printf("\n");
	cout<<"mask_off-----";
	unsigned int *m2 = (unsigned int *)mask_off;
	printf("%08x", m2[0]);
	printf("%08x", m2[1]);
	printf("%08x", m2[2]);
	printf("%08x\n", m2[3]);
	printf("%d", m2[3]);
	printf("\n");
}

void dumpData(){
	unsigned int *m = (unsigned int *)data;
	cout<<"data-----";
	printf("%x", m[0]);
	printf("%x", m[1]);
	printf("%x", m[2]);
	printf("%x", m[3]);
	printf("\n");
}

void dumpSorted(){
	cout<<"sort    ";
	unsigned int *m = (unsigned int *)sorted_datas;
	for(int i=0;i<(sorted_len*2);i++){
		printf("%08x", m[i]);
	}
	printf("\n");
}

void insert_sort(long v1, long v2){	//对data作插入排序
	int i, j;
	for(i=0;i<sorted_len;i+=2){
		if(v1>sorted_datas[i] || (v1==sorted_datas[i] && v2>sorted_datas[i+1])){	//从小到大排序
			break;
		} else if(v1==sorted_datas[i] && v2==sorted_datas[i+1]){
			return;
		}
	}
	for(j=sorted_len-1;j>=i;j-=2){	//把当前到最后的都往后挪两个
		sorted_datas[j+2]=sorted_datas[j];
		sorted_datas[j+1]=sorted_datas[j-1];
	}
	//cout<<hex<<data[0]<<data[1]<<endl;
	sorted_datas[i]=v1;
	sorted_datas[i+1]=v2;
	sorted_len+=2;
	//binDump(v1, v2, 10);
}

bool check_mask_on(){
	if(((data[0] & mask_on[0]) == mask_on[0]) &&
	((data[1] & mask_on[1]) == mask_on[1])){
		return true;
	} else {
		return false;
	}
}

bool check_mask_off(){
	if(((data[0] & mask_off[0]) == 0) &&
	((data[1] & mask_off[1]) == 0)){
		return true;
	} else {
		return false;
	}
}

void subs(int offset, int len){
	if(len==0){	//选完组合了
		if(check_mask_on() && check_mask_off()){
			insert_sort(data[0], data[1]);	
		}
	} else{
		for(int i=offset;i<(OPER_NUM-len+1);i++){
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
	while(1){	//构造掩码 on
		fin>>t;
		if(t==-1){
			break;
		}
		if(t<64){
			mask_on[0] = mask_on[0] | ((long)1)<<(t-1);
		} else {
			mask_on[0] = mask_on[0] | ((long)1)<<(t-64);
		}
	}
	while(1){	//构造掩码 off
		fin>>t;
		if(t==-1){
			break;
		}
		if(t<64){
			mask_off[1] = mask_off[1] | ((long)1)<<(t-1);
		} else {
			mask_off[0] = mask_off[0] | ((long)1)<<(t-64);
		}
	}
	while(C>=0){
		if(C<=4){
			subs(0, C);
		}
		C-=2;
	}
	if(sorted_len==0){
		fout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	for(int i=sorted_len-2;i>=0;i-=2){
		binDump(sorted_datas[i], sorted_datas[i+1], N, fout);
	}
	
    return 0;
}