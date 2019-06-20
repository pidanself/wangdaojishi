#include<iostream>
using namespace std;
//导弹高度
int h[26]={0};
//以h[i]结尾的最多拦截数
int dp[26]={0}; 
//导弹数 
int k=0;


int main(){
	
	while(scanf("%d",&k)!=EOF){
		for(int i=0;i<k;i++){
			cin>>h[i];
		}
		int ans=0;
		for(int i=0;i<k;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(h[i]<=h[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		}
		cout<<"最大拦截数为："<<ans<<endl;
	}

	return 0;
}

