#include<iostream>
using namespace std;
//同学总数
int n;
//同学的身高
int h[101]; 
//以第i个同学为终止的最长递增子序列
int dps[101];
//以第i个同学为终止的逆最长递增子序列
int dpn[101];


int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		//求顺
		for(int i=0;i<n;i++){
			dps[i]=1;
			for(int j=0;j<i;j++){
				if(h[j]<h[i]){
					dps[i]=max(dps[i],dps[j]+1);
				}
			}
		} 
		//求逆
		for(int i=n-1;i>=0;i--){
			dpn[i]=1;
			for(int j=n-1;j>i;j--){
				if(h[j]<h[i]){
					dpn[i]=max(dpn[i],dpn[j]+1);
				}
			}
		} 
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,dps[i]+dpn[i]);
		}
		cout<<"最少出列："<<n-ans+1<<"名学生"<<endl; 
	}

	return 0;
}

