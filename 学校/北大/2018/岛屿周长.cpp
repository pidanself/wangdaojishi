#include<iostream>
using namespace std;
int dir[4][2]={
	1,0,
	-1,0,
	0,1,
	0,-1
};
int ju[101][101];
int n,m;
int ans=0;
void dp(int i,int j){
	ju[i][j]=2;
	for(int k=0;k<4;k++){
		int x,y;
		x=i+dir[k][0];
		y=j+dir[k][1];
		if(x>=1&&x<=n&&y>=1&&y<=m){
			if(ju[x][y]==1){
				dp(x,y);
			}
			else if(ju[x][y]==0){
				ans++;
			}
		}
		else{
			ans++;
		}
	}
}


int main(){
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ju[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ju[i][j]==1){
				dp(i,j);
			}
		}
	}
	cout<<ans;

	return 0;
}

