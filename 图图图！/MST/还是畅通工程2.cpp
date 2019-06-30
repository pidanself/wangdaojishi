#include<iostream>
#include<algorithm>
using namespace std;

int tree[101];

struct edge{
	int a,b;
	int c;
}e[101];

bool cmp(edge e1,edge e2){
	return e1.c<e2.c;
}

int findroot(int a){
	if(tree[a]==a) return a;
	else{
		int tmp=findroot(tree[a]);
		tree[a]=tmp;
		return tmp;
	}
}

int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		tree[i]=i;
	}
	for(int i=0;i<n*(n-1)/2;i++){
		int p1,p2,p3;
		scanf("%d %d %d",&p1,&p2,&p3);
		e[i].a=p1;
		e[i].b=p2;
		e[i].c=p3;
	}
	sort(e,e+n*(n-1)/2,cmp);
	int ans=0;
	for(int i=0;i<n*(n-1)/2;i++){
		int r1,r2;
		r1=findroot(e[i].a);
		r2=findroot(e[i].b);
		if(r1==r2) continue;
		else{
			ans+=e[i].c;
			tree[r2]=r1;
		}
	}
	
	cout<<ans;
	return 0;
}

