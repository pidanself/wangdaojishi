#include<iostream>
#include<vector>
using namespace std;

//可以永并查集做

//以下为对dfs的尝试 
class Solution {
public:
    int findCircleNum(vector<vector<int> >& M) {
    	int nums=0;
    	bool flag[201]={0};
        if(M.empty()){
        	return nums;
		}
		else{
			for(int i=0;i<M.size();i++){
				 if(flag[i]==false){
				 	dfs(i,flag,M);
				 	nums++;
				 }
			}
		}
		return nums;
    }
    
    void dfs(int i,bool flag[],vector<vector<int> >& M){
    	flag[i]=true;
    	
    	for(int j=0;j<M[i].size();j++){
    		if(flag[j]==false&&M[i][j]==1){
    			dfs(j,flag,M);
			}
		}
	}
    
};


int main(){





	return 0;
}

