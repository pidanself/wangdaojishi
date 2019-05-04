#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct edge{
	int a,b;
	int cost;
	bool operator < (const edge &A) const{
		
		return cost<A.cost;
	} 
}e[6000];

int par[101]={0};

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
		int a,b,cost,ok;
		for(int i=1;i<=n*(n-1)/2;i++){
			scanf("%d%d%d%d",&a,&b,&cost,&ok);
			e[i].a=a;
			e[i].b=b;
			e[i].cost=cost;
			if(ok==1){
				e[i].cost=0;
			}
		}
		
		sort(e+1,e+1+n*(n-1)/2);
		int ans=0;
		for(int i=1;i<=n*(n-1)/2;i++){
			int p1=findroot(e[i].a);
			int p2=findroot(e[i].b);
			
			if(p1==p2){
				continue;
			}
			else{
				ans+=e[i].cost;
				par[p1]=p2;
			}
		}
		cout<<ans<<endl;
		memset(par,0,sizeof(par));
		
	}


	return 0;
}

