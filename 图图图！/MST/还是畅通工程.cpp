#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int par[101]={0};
struct edge{
	int a,b;
	int cost;
	
	bool operator < (const edge &A) const{
		return cost<A.cost;
	}
	
}e[5000]; 

int findroot(int x){
	if(par[x]==0){
		return x;
	}
	int tmp=findroot(par[x]);
	par[x]=tmp;
	return tmp;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int a,b;
		for(int i=1;i<=n*(n-1)/2;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].cost);
		}
		
		sort(e+1,e+1+n*(n-1)/2);
		int ans=0;
		for(int i=1;i<=n*(n-1)/2;i++){
			int p1,p2;
			p1=findroot(e[i].a);
			p2=findroot(e[i].b);
			if(p1!=p2){
				par[p1]=p2;
				ans+=e[i].cost;
			}
		}
		cout<<ans<<endl;
		ans=0;
		memset(par,0,sizeof(par));
	}


	return 0;
}

