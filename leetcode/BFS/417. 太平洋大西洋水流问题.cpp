#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//尝试老老实实对每个点进行bfs搜索
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
		
		//遍历每块陆地 
		for(int i=0;i<l;i++){
			for(int j=0;j<w;j++){
				bfs(matrix,i,j,Pacific,1);
				bfs(matrix,i,j,Atlantic,2);
			}
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
    
    
    void bfs(vector<vector<int> >& m,int y,int x,bool visit[151][151],int type){
    	bool fang[151][151]={0};
    	queue<vector<int> > q;
    	vector<int> v;v.push_back(y);v.push_back(x);v.push_back(m[y][x]);
		q.push(v);
		fang[y][x]=true;
		//太平洋 
		if(type==1){
    		while(!q.empty()){
    			vector<int> t=q.front();
    			if(t[0]==0||t[1]==0){
    				visit[y][x]=true;
    				return;
				}
				else{
					for(int i=0;i<4;i++){
						int yy=dir[i][0]+t[0];
						int xx=dir[i][1]+t[1];
						if(yy<m.size()&&yy>=0&&xx<m[0].size()&&x>=0){
							if(m[yy][xx]<=t[2]&&!fang[yy][xx]){
								fang[yy][xx]=true;
								vector<int> t;t.push_back(yy);t.push_back(xx);t.push_back(m[yy][xx]);
								q.push(t);
							}
						}
					}
				}
				q.pop();
			}
		}else{
			while(!q.empty()){
    			vector<int> t=q.front();
    			if(t[0]==(m.size()-1)||t[1]==(m[0].size()-1)){
    				visit[y][x]=true;
    				return;
				}
				else{
					for(int i=0;i<4;i++){
						int yy=dir[i][0]+t[0];
						int xx=dir[i][1]+t[1];
						if(yy<m.size()&&yy>=0&&xx<m[0].size()&&x>=0){
							if(m[yy][xx]<=t[2]&&!fang[yy][xx]){
								fang[yy][xx]=true;
								vector<int> t;t.push_back(yy);t.push_back(xx);t.push_back(m[yy][xx]);
								q.push(t);
							}
						}
					}
				}
				q.pop();
			}
		}
	}
	
private:
	int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
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

