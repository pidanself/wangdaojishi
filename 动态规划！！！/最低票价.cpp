#include<iostream>
using namespace std;

int main(){
	int days[]={1,4,6,7,8,20};
	int costs[]={2,7,15},index=0;
	int dp[366];
	dp[0]=0;
	for(int i=1;i<=365;i++){
		if(i!=days[index]){
			dp[i]=dp[i-1];
			continue;
		}
		index++;
		dp[i]=min(dp[max(i-1,0)]+costs[0],min(dp[max(i-7,0)]+costs[1],dp[max(0,i-30)]+costs[2]));
		if(index==6) break;
	}
	cout<<dp[days[index-1]];

	return 0;
}

