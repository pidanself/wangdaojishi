#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) {
        bool Pacific[151][151]={0};
		bool Atlantic[151][151]={0};
		vector<vector<int> > ans;
		int w,l;
		if(matrix.empty()) return ans;
		else{
			l=matrix.size();
			w=matrix[0].size();
		}
		
		//对四边进行dfs
		for(int i=0;i<l;i++){
			dfs(matrix,i,0,Pacific,matrix[i][0]);
			dfs(matrix,i,w-1,Atlantic,matrix[i][w-1]);
		} 
		for(int j=0;j<w;j++){
			dfs(matrix,0,j,Pacific,matrix[0][j]);
			dfs(matrix,l-1,j,Atlantic,matrix[l-1][j]);
		}
		
		//遍历每个点判断是否能够都到达
		for(int i=0;i<l;i++){
			for(int j=0;j<w;j++){
				if(Pacific[i][j]&&Atlantic[i][j]){
					vector<int> t;
					t.push_back(i);
					t.push_back(j);
					ans.push_back(t);
				}
			}
		} 
		return ans;
    }
    
    void dfs(vector<vector<int> >& m,int y,int x,bool visit[151][151],int pre){
    	if(x<0||y<0||x>=m.size()||y>=m[0].size()||visit[x][y]||m[x][y]<pre){
    		return;
		}
		
		return ;
	}
};


int main(){


	return 0;
}

