#include<iostream>
using namespace std;

class checkAndSet{
	public:
		
		
	private:
		#define MAX_N 10000
		int par[MAX_N];
		int rank[MAX_N];
		
		//初始化
		void init(int n){
			for(int i=0;i<n;i++){
				par[i]=i;
				rank[i]=0;
			}
		}
		
		//寻找root
		int findRoot(int x){
			if(par[x]==x){
				return x;
			}
			else{
				int t=findRoot(par[x]);
				par[x]=t;
				return t;
			}
		}
		
		//合并集合
		void unite(int x,int y){
			int xRoot,yRoot;
			xRoot=findRoot(x);
			yRoot=findRoot(y);
			
			if(xRoot==yRoot){
				return;
			}
			else{
				if(rank[xRoot]<rank[yRoot]){
					par[xRoot]=yRoot;
				}
				else{
					par[yRoot]=xRoot;
					if(rank[xRoot]==rank[yRoot]){
						rank[yRoot]++;
					}
				}
			}
		} 
};

int main(){





	return 0;
}

