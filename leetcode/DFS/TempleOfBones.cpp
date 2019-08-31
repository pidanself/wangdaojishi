//热身局 
#include<iostream>
using namespace std;

//layout of maze:
//S:the start point of the doggie
//D:the Door
//.:an empty block
//X:a block of wall

char maze[7][7];
int N,M,T;
int dx,dy;
bool success;
int go[][2]={1,0,-1,0,0,1,0,-1};

void dfs(int x,int y,int t);


int main(){
	
	while(scanf("%d%d%d",&N,&M,&T)!=EOF){
		if(N==0&&M==0&&T==0) break;
		//初始化标记
		success=false; 
		//输入 
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>maze[i][j]; 
			}
		}
		//寻找D
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(maze[i][j]=='D'){
					dx=i;
					dy=j;
				} 
			}
		}
		//寻找S
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(maze[i][j]=='S'){
					maze[i][j]='X';
					dfs(i,j,0); 
				} 
			}
		}
		puts(success==true ? "YES":"NO");
	}
	return 0;
}

 
void dfs(int x,int y,int t){
	if(t>T) return;
	for(int i=0;i<4;i++){
		int nx,ny;
		nx=x+go[i][0];
		ny=y+go[i][1];
		if(nx<0||nx>=N||ny<0||ny>=M) continue;
		if(maze[nx][ny]=='X') continue;
		if(maze[nx][ny]=='D'){
			if(t+1==T){
				success=true;
				return;
			}
			else{
				continue;
			}
		}
		maze[nx][ny]='X';
		dfs(nx,ny,t+1);
		maze[nx][ny]='.';
		if(success) return;
	}
	 
} 
 

