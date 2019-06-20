#include<iostream>
#include<cstring>
using namespace std;
int maze[7][7];
int go[][2]={
	0,1,
	0,-1,
	1,0,
	-1,0
};
int n;
int m;
int t;
bool mark[7][7]={0};
bool ans=false;
//0-S
//1-.
//2-X
//3-D
void dfs(int x,int y,int tt){
	if(ans) return;
	if(maze[x][y]==3&&tt==t){
		ans=true;
		return;
	}
	
	
	
	for(int i=0;i<4;i++){
		int nx,ny;
		nx=x+go[i][0];
		ny=y+go[i][1];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(mark[nx][ny]==false){
				if(maze[nx][ny]!=2){
					mark[nx][ny]=true;
					dfs(nx,ny,tt+1);
					mark[nx][ny]=false;
				}
			}
		}
	}
}


int main(){
	
	
	
	while(scanf("%d %d %d",&n,&m,&t)!=EOF&&n!=0){
		//ÊäÈëmaze
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>maze[i][j];
			}
		} 
		dfs(0,0,0);
		if(ans) cout<<"Yes";
		else cout<<"NO";
		cout<<endl;
	}
	

}

