#include<iostream>
#include<cstring>
using namespace std;
int nums[1000001];

int main(){
	memset(nums,-1,sizeof(nums));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		nums[t+500000]=t;
	}
	
	for(int i=1000000;i>=0;i--){
		if(nums[i]!=-1){
			if(m==1){
				cout<<nums[i];
				break;
			}
			else{
				cout<<nums[i]<<" ";
			}
			m--;
		}
	}

	return 0;
}

