#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
    	int ans=0;
    	if(M.empty()){
    		return ans;
		}
		else{
			//初始化
			init(M.size());
			//合并集合 
			for(int i=0;i<M.size();i++){
				for(int j=0;j<M[0].size();j++){
					if(i!=j){
						if(M[i][j]==1){
							unite(i,j);
						}
					}
				}
			}
			//计数
			for(int i=0;i<M.size();i++){
				if(par[i]==i){
					ans++;
				}
			} 
			return ans;
		}
    }
private:
	#define MAX_N 10000
	int par[MAX_N];
	int rank[MAX_N];
	
	//init n
	void init(int n){
		for(int i=0;i<n;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	
	//find your root
	int find(int x){
		if(par[x]==x){
			return x;
		}
		else{
			int tmp=find(par[x]);
			par[x]=tmp;
			return tmp;
		}
	}
	
	//unite sets
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]){
			par[x]=y;
		}
		else{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	
	//judge
	bool same(int x,int y){
		return find(x)==find(y);
	} 

};

int main(){





	return 0;
}

