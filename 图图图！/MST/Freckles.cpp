#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int par[101]={0};

struct point{
	float x,y;
	float getdistance(point A){
		float t=(x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);
		return sqrt(t);
	}
}p[101];

struct edge{
	int a,b;
	float d;
	
	bool operator < (const edge &A) const{
		return d<A.d;
	}
}e[6000];

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
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	int index=1;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			e[index].a=i;
			e[index].b=j;
			e[index].d=p[i].getdistance(p[j]);
			index++;
		}
	}
	
	sort(e+1,e+1+n*(n-1)/2);
	float ans=0;
		for(int i=1;i<=n*(n-1)/2;i++){
			int p1,p2;
			p1=findroot(e[i].a);
			p2=findroot(e[i].b);
			if(p1!=p2){
				par[p1]=p2;
				ans+=e[i].d;
			}
		}
	printf("%.2f",ans);


	return 0;
}

