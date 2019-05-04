//毫无难度 我真牛逼 
#include<iostream>
using namespace std;
int par[1001];
int findroot(int x){
	if(par[x]==x){
		return x;
	}
	int tmp=findroot(par[x]);
	par[x]=tmp;
	return tmp;
} 



int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		//initial
		for(int i=1;i<=n;i++){
			par[i]=i;
		}
		int e1,e2;
		for(int i=0;i<m;i++){
			scanf("%d%d",&e1,&e2);
			int x=findroot(e1),y=findroot(e2);
			if(x==y) continue;
			else{
				par[x]=y;
			}
		}
		int rootnums=0;
		for(int i=1;i<=n;i++){
			if(par[i]==i){
				rootnums++;
			}
		}
		if(rootnums==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}


	return 0;
}

