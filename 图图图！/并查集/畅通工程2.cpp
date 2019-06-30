#include<iostream>
using namespace std;
int tree[1001]; 

int findroot(int a){
	if(tree[a]==a) return a;
	else{
		int tmp=findroot(tree[a]);
		tree[a]=tmp;
		return tmp;
	}
}

void merge(int x,int y){
	int t1,t2;
	t1=findroot(x);
	t2=findroot(y);
	if(x!=y){
		tree[t2]=t1;
	}
}

int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF&&n!=0){
		for(int i=1;i<=n;i++){
			tree[i]=i;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			merge(a,b);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(tree[i]==i){
				ans++;
			}
		}
		ans--;
		cout<<ans;
	}
	

	return 0;
}

