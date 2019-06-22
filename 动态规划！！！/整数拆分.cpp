#include<iostream>
using namespace std;

int main(){
	int dp[11]={0};
	dp[2]=1;
	dp[3]=2;
	for(int i=4;i<11;i++){
		
		for(int j=2;j<i;j++){
			dp[i]=max(dp[i],max((i-j)*dp[j],(i-j)*j));
		}
	} 
	cout<<dp[10];

	return 0;
}

