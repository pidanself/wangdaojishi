#include<iostream>
using namespace std;
char maze[8][8];
int a,b,T;
int go[][2]{
	0,1,
	0,-1,
	1,0,
	-1,0
};
bool success=0;
void dfs(int x,int y,int t){
	for(int i=0;i<4;i++){
		int nx,ny;
		nx=x+go[i][0];
		ny=y+go[i][1];
		if(nx<0||nx>=a||ny<0||ny>=b) continue;
		if(maze[nx][ny]=='X') continue;
		if(maze[nx][ny]=='D'){
			if(t+1==T){
				success=true;
				return ;
			}
			else{
				continue;
			}
		}
		if(maze[nx][ny]=='.'){
			if(t+1>=T) continue;
			maze[nx][ny]='X';
			dfs(nx,ny,t+1);
			maze[nx][ny]='.';
		}
		if(success) return;
	}
}


int main(){
	scanf("%d %d %d",&a,&b,&T);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			//scanf("%c",&maze[i][j]);
			cin>>maze[i][j];
		}
	}
	dfs(0,0,0);
	
	if(success==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}

	return 0;
}

