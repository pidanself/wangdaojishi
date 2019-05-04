#include<iostream>
#include<cstring> 
using namespace std;

int road[101][101]={0};

int main(){
	int n,m;
	//目标是1到n的路口最短路径 
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0){
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(road[a][b]==0){
				road[a][b]=c;
				road[b][a]=c;
			}
			else{
				int minn=min(c,road[a][b]);
				road[a][b]=minn;
				road[b][a]=minn;
			}
		}
		
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(road[i][k]==0||road[k][j]==0){
						continue;
					}
					if(road[i][j]==0||road[i][j]>road[i][k]+road[k][j]){
						road[i][j]=road[i][k]+road[k][j];
					}
				}
			}
		} 
		
		cout<<"最短路径为"<<road[1][n]<<endl;
		memset(road,0,sizeof(road));
	}
	

	return 0;
}

