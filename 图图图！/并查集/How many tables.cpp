#include<iostream>
using namespace std;

int par[1001];

int findroot(int x){
	if(x==par[x]){
		return x;
	}
	int tmp=findroot(x);
	par[x]=tmp;
	return tmp;
}

int main(){
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		//inite
		for(int i=1;i<=n;i++){
			par[i]=i;
		}
		for(int i=0;i<m;i++){
			int e1,e2;
			cin>>e1>>e2;
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
		cout<<rootnums<<endl;
		cout<<endl;
	}


	return 0;
}

