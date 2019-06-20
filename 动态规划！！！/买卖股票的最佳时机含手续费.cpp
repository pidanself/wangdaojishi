#include<iostream>
using namespace std;

int main(){
	int dp[50000][2];
	int prices[6]={1, 3, 2, 8, 4, 9};
	int fee=2;
	dp[0][0]=0;
	dp[0][1]=-prices[0];
	for(int i=1;i<6;i++){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
			dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
	
	}
	cout<<dp[5][0];
	
	return 0;
}

