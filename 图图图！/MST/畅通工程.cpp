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
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		int a,b;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].cost);
		}
		
		sort(e+1,e+1+n);
		int ans=0;
		for(int i=1;i<=n;i++){
			int p1,p2;
			p1=findroot(e[i].a);
			p2=findroot(e[i].b);
			if(p1!=p2){
				par[p1]=p2;
				ans+=e[i].cost;
			}
		}
		int rootnum=0;
		for(int i=1;i<=n;i++){
			if(par[i]==0){
				rootnum++;
			}
		} 
		if(rootnum>=1){
			cout<<"?"<<endl;
		}
		else{
			cout<<ans<<endl;
		}
		ans=0;
		memset(par,0,sizeof(par));
	}


	return 0;
}

