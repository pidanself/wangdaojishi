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
		
		//从四个海边进行dfs
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
    	if(x<0||y<0||y>=m.size()||x>=m[0].size()||visit[y][x]||m[y][x]<pre){
    		return;
		}
		visit[y][x]=true;
		dfs(m,y,x+1,visit,m[y][x]);
		dfs(m,y,x-1,visit,m[y][x]);
		dfs(m,y+1,x,visit,m[y][x]);
		dfs(m,y-1,x,visit,m[y][x]);
	}
};


int main(){
	Solution solution;
	vector<vector<int> > v;
	vector<int> v1;
	vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(4);
	v2.push_back(3);
	v.push_back(v1);
	v.push_back(v2);
	
	v=solution.pacificAtlantic(v);
	
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[0].size();j++){
			cout<<v[i][j]<<",";
		}
		cout<<endl;
	}

	return 0;
}

