#include<iostream>
using namespace std;

int main(){
	
	int n,k,r,c;
	cin>>n>>k>>r>>c;
	double dp[26][26][101];
	int dir[][2]={
		1,-2,
		2,-1,
		2,1,
		1,2,
		-1,2,
		-2,1,
		-2,-1,
		-1,-2
	};
	
	//初始化数组
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j][0]=1;
		}
	} 
	//进行k次循环 
	for(int kk=1;kk<=k;kk++){
		//对棋盘上所有点进行遍历
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				double anst=0; 
				//八种走法 
				for(int t=0;t<8;t++){
					int rt,ct;
					rt=i+dir[t][0];
					ct=j+dir[t][1];
					if(rt>=0&&ct>=0&&rt<=(n-1)&&ct<=(n-1)){
						anst+=dp[rt][ct][kk-1];
					}
				}
				dp[i][j][kk]=anst/8.0;
			}
		} 
	}
	cout<<dp[r][c][k];
	return 0;
}

