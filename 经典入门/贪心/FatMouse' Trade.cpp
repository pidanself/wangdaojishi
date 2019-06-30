#include<iostream>
#include<algorithm>
using namespace std;

struct goods{
	double j,f;
	double x; 
};

bool cmp(goods g1,goods g2){
	return g1.x>g2.x;
}

int main(){
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF){
		if(m==-1&&(n==-1)){
			break;
		}
		goods g[n];
		for(int i=0;i<n;i++){
			cin>>g[i].j>>g[i].f;
			g[i].x=g[i].j/g[i].f;
		}
		sort(g,g+n,cmp);
		int idx=0;
		double ans=0; 
		while(m>0&&idx<n){
			if(m>g[idx].f){
				ans+=g[idx].j;
				m-=g[idx].f;
				idx++;
			}
			else{
				ans+=m*g[idx].x;
				m=0;
				break;
			}
		}
		printf("%.3lf\n",ans);
	}

	return 0;
}

