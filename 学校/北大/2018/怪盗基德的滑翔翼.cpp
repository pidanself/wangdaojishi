#include<iostream>
using namespace std;
int h[100];
int dp[100]={0};
int dpp[100]={0};
int main(){
	int n,k;
	cin>>k;
	for(int p=0;p<k;p++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>h[i];
			dp[i]=1;
			dpp[i]=1;
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(h[i]>h[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
				if(h[i]<h[j]){
					dpp[i]=max(dpp[i],dpp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
			ans=max(ans,dpp[i]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

