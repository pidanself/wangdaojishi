#include<iostream>
using namespace std;
//�����߶�
int h[26]={0};
//��h[i]��β�����������
int dp[26]={0}; 
//������ 
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
		cout<<"���������Ϊ��"<<ans<<endl;
	}

	return 0;
}

