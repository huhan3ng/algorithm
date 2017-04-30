/*
ID: huhan3n1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define max(a, b) ((a)>(b)?(a):(b))
#define FLAG_SQUARE 10000
using namespace std;

unsigned int M;
unsigned int N;
unsigned int B[50][50]={0};
unsigned int visited[50][50]={0};
unsigned int w[102][102]={0};
unsigned int cnt[50*50+1]={0};
unsigned int room,x,y;
char direction;

int maxVal(unsigned int *s, int num){
	int ret=0;
	for(int i=0;i<=num;i++){
		//cout<<"si "<<s[i]<<endl;
		ret = max(ret, s[i]);
	}
	return ret;
}

void createWalls(int i, int j){	//为单个方块建墙
	if(B[i][j] & 0b0001)	//1
		w[2*i+1][2*j]++;
	if(B[i][j] & 0b0010)	//2
		w[2*i][2*j+1]++;
	if(B[i][j] & 0b0100)	//4
		w[2*i+1][2*j+2]++;
	if(B[i][j] & 0b1000)	//8
		w[2*i+2][2*j+1]++;
}

void buildWalls(){	//为整个房间建墙
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			createWalls(i, j);
		}
	}
}

void fillRoom(int i, int j, int c){
	visited[i][j]=c;	//标记为已访问
	cnt[c]++;
	//cout<<"count"<<cnt[c]<<endl;
	if(!w[2*i+1][2*j] && !visited[i][j-1]){
		fillRoom(i, j-1, c);	//左
	}
	if(!w[2*i][2*j+1] && !visited[i-1][j]){
		fillRoom(i-1, j, c);	//上
	}
	if(!w[2*i+1][2*j+2] && !visited[i][j+1]){
		fillRoom(i, j+1, c);	//右
	}
	if(!w[2*i+2][2*j+1] && !visited[i+1][j]){
		fillRoom(i+1, j, c);	//下
	}
}

void fillCastle(){
	room=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!visited[i][j]){
				fillRoom(i, j, room);
				//cout<<"****++++++"<<room<<" "<<i*M+j<<endl;
				room++;
				//cout<<"****------"<<room<<" "<<i*M+j<<endl;
			}
		}
	}
}

int breakWall(int i, int j){	//找到墙两边的square，得到房间编号，相加房间面积
	int i1,i2,j1,j2;
	if(i%2==0){	//横墙
		j1=(j-1)/2;
		j2=(j-1)/2;
		i1=(i)/2;
		i2=(i-2)/2;
	}
	if(j%2==0){	//竖墙
		i1=(i-1)/2;
		i2=(i-1)/2;
		j1=(j)/2;
		j2=(j-2)/2;
	}
	//cout<<"---------"<<i1<<" "<<i2<<" "<<j1<<" "<<j2<<" "<<endl;
	if(visited[i1][j1]==visited[i2][j2]){
		return cnt[visited[i1][j1]];
	} else {
		return cnt[visited[i1][j1]]+cnt[visited[i2][j2]];
	}
}

int breakWalls(){
	int val=0,v1;
	for(int j=0;j<M;j++){
		for(int i=N-1;i>=0;i--){
			if(w[2*i][2*j+1]){	//N
				v1=breakWall(2*i, 2*j+1);
				if(val<v1){
					val=v1;
					x=i+1;
					y=j+1;
					direction='N';						
				}
			}
			if(w[2*i+1][2*j+2]){
				v1=breakWall(2*i+1, 2*j+2);
				if(val<v1){
					val=v1;
					x=i+1;
					y=j+1;
					direction='E';
				}
			}
		}
	}
	return val;
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
	fin>>M>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			fin>>B[i][j];
			//cout<<B[i][j]<<" ";
		}
		//cout<<endl;
	}
	buildWalls();
	if(0){
		for(int i=0;i<(2*N+2);i++){
			for(int j=0;j<(2*M+2);j++){
				cout<<w[i][j]<<" ";
			}
			cout<<endl;
		}		
	}
	fillCastle();
	if(0){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cout<<visited[i][j]<<" ";
			}
			cout<<endl;
		}	
	}
	int t=breakWalls();
	if(0){
		cout<<room-1<<endl;
		cout<<maxVal(cnt, room-1)<<endl;
		cout<<t<<endl;
		cout<<x<<" "<<y<<" "<<direction<<endl;
	}
	fout<<room-1<<endl;
	fout<<maxVal(cnt, room-1)<<endl;
	fout<<t<<endl;
	fout<<x<<" "<<y<<" "<<direction<<endl;
	//cout<<breakWall(7, 2)<<endl;
    return 0;
}