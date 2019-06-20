#include<iostream>
using namespace std;
int grid[101][101];
int m,n;
int go[][2]={
	1,0,
	-1,0,
	1,1,
	0,1,
	-1,1,
	1,-1,
	0,-1,
	-1,-1
};

void mark(int x,int y){
	for(int i=0;i<8;i++){
		int tx,ty;
		tx=x+go[i][0];
		ty=y+go[i][1];
		if(tx>=0&&tx<m&&ty>=0&&ty<n){
			if(grid[tx][ty]==1){
				grid[tx][ty]=0;
				mark(tx,ty);
			}
		}
	}
}

int main(){
	
	while(scanf("%d %d",&m,&n)!=EOF&&m!=0){
		int ans=0;
		//input
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>grid[i][j];
			}
		}
		
		//dispose
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==1){
					ans++;
					grid[i][j]=0;
					mark(i,j);
				}
			}
		}
		cout<<ans<<endl;
	}


}

