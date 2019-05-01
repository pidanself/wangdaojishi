#include<iostream>
#include<cstring>
using namespace std;
#define N 10000001
int Tree[N];
int findRoot(int i){
	if(Tree[i]==-1) return i;
	else{
		int tmp=findRoot(Tree[i]);
		Tree[i]=tmp;
		return tmp;
	}
} 

int sum[N]={0};
int main(){
	int A,B,n;
	int ans=0;
	memset(Tree,-1,sizeof(Tree));
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=N;i++){
			sum[i]=1;
		}
		for(int i=0;i<n;i++){
			scanf("%d%d",&A,&B);
			A=findRoot(A);
			B=findRoot(B);
			if(A!=B){
				Tree[B]=A;
				sum[A]+=sum[B];
				sum[B]=1;
				ans=max(ans,sum[A]);
			}
		}
		cout<<ans;
		//inite
		memset(sum,0,sizeof(sum));
		ans=0;
		memset(Tree,-1,sizeof(Tree));
	}


	return 0;
}

