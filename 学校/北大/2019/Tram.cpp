#include<iostream>
#include<cstring>
using namespace std;
int edge[101][101];


int main(){
	memset(edge,-1,sizeof(edge));
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               edge[i][j]=(i==j?0:-1);
           }
       }
	for(int i=1;i<=n;i++){
		int nums;
		cin>>nums;
		for(int j=0;j<nums;j++){
			int t;
			cin>>t;
			if(t==0){
				edge[i][t]=0;
			}
			else{
				edge[i][t]=1;
			}
		}
	}
	
	//floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(edge[i][k]==-1||edge[k][j]==-1) continue;
				if(edge[i][j]==-1||(edge[i][k]+edge[k][j]<edge[i][j])){
					edge[i][j]=edge[i][k]+edge[k][j];
				} 
			}
		}
	}
	if(edge[a][b]==-1){
		cout<<edge[a][b]<<endl;
	}
	else{
		cout<<edge[a][b]-1<<endl;
	}
	
	return 0;
}
