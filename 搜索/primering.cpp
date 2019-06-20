#include<iostream>
using namespace std;
int n;
int hash[17]={0};
int ans[17]={0};
int prime[]={2,3,5,7,11,13,17,19,23,29,31};

bool judge(int x){
	for(int i=0;i<sizeof(prime)/sizeof(int);i++){
		if(prime[i]==x) return true;
	}
	return false;
}

void dfs(int h){
	if(h==n+1&&(judge(ans[n]+1))){
		//Êä³ö²¢·µ»Ø
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		} 
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(hash[i]==0&&(judge(ans[h-1]+i))){
			hash[i]=1;
			ans[h]=i;
			dfs(h+1);
			hash[i]=0;
			ans[h]=0;
		}
	}
}

int main(){
	
	
	ans[1]=1;
	hash[1]=1;
	while(scanf("%d",&n)!=EOF&&n!=0){
		dfs(2);
	}


}

