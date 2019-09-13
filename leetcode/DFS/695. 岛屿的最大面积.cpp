#include<iostream>
#include<vector>
using namespace std;
int dir[][2]={1,0,-1,0,0,1,0,-1};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	if(grid.empty()){
    		return 0;
		}
        int ans=0;
        for(int i=0;i<grid.size();i++){
        	for(int j=0;j<grid[i].size();j++){
        		if(grid[i][j]==1){
        			ans=max(ans,dfs(i,j,grid));
				}
			}
		}
		return ans;
    }
    int dfs(int i,int j,vector<vector<int>>& grid){
    	int ans=1;
    	grid[i][j]=0;
    	for(int x=0;x<4;x++){
    		int in,jn;
    		in=i+dir[x][0];
    		jn=j+dir[x][1];
    		if(in>=0&&in<grid.size()&&jn>=0&&jn<grid[in].size()){
    			if(grid[in][jn]==1){
    				ans+=dfs(in,jn,grid);
				}
			}
		}
		return ans;
	}
};

int main(){


	return 0;
}

