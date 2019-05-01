#include<iostream>
using namespace std;
int Tree[1001];
int findRoot(int i){
	if(Tree[i]==-1) return i;
	else{
		int t=findRoot(Tree[i]);
		Tree[i]=t;
		return t;
	}
}


int a,b;//道路
int n,m;//城镇数目为n，道路数目为m 

int main(){
	
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		//初始化并查集
		for(int i=0;i<1000;i++){
			Tree[i]=-1;
		} 
		
		//输入道路 
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b) Tree[b]=a;
		}
		
		int ans=0;
		//统计根的数目
		for(int i=1;i<=n;i++){
			if(Tree[i]==-1) ans++;
		} 
		cout<<(ans-1)<<endl;
	}

	return 0;
}

