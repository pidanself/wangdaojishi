#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
	struct point{
		int x,y;
	};
public:
    int shortestBridge(vector<vector<int>>& A) {
        h=A.size();
        w=A[0].size();
        for(int i=0;i<h;i++){
        	for(int j=0;j<w;j++){
        		if(A[i][j]==1){
        			point t;
        			t.x=j;
        			t.y=i;
        			//将该岛都变为2，并将岛边缘放入v中 
        			dfs(A,t);
        			goto fan;
				}
			}
		}
	fan:
		int ans=0;
		int size=0;
		
		while(!v.empty()){
			size=v.size();
			ans++;
			for(int i=0;i<size;i++){
				point p=v.front();
				//对其四周进行扩散
				for(int j=0;j<4;j++){
					int x,y;
					x=p.x+dir[j][0];
					y=p.y+dir[j][1];
					if(x>=0&&x<w&&y>=0&&y<h){
						if(A[y][x]==0){
							if(tong(x,y,A)){
								return ans;
							}
							else{
								A[y][x]=2;
								point tt;
								tt.x=x;
								tt.y=y;
								v.push(tt);
							}
						}
					}
				} 
				v.pop();
			}
		}
		return ans;
    }
    
    bool tong(int x,int y,vector<vector<int>>& A){
		//对其四周进行扩散
		for(int j=0;j<4;j++){
			int xx,yy;
			xx=x+dir[j][0];
			yy=y+dir[j][1];
			if(xx>=0&&xx<w&&yy>=0&&yy<h){
				if(A[yy][xx]==1){
					return true;
				}
			}
		} 
		return false;
	}
    
    void dfs(vector<vector<int>>& A,point p){
    	A[p.y][p.x]=2;
    	bool ifedge=false;
		for(int i=0;i<4;i++){
			int x,y;
			x=p.x+dir[i][0];
			y=p.y+dir[i][1];
			if(x>=0&&x<w&&y>=0&&y<h){
				if(A[y][x]==1){
					point t;
					t.x=x;
					t.y=y;
					dfs(A,t);
				}
				else if(A[y][x]==0){
					ifedge=true;				
				}
			}
		}
		if(ifedge){
			v.push(p);
		} 
	}
    
private:
	queue<point> v;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int w,h;
};

int main(){
	vector<vector<int>> A;
	vector<int> a1;
	a1.push_back(0);
	a1.push_back(1);
	a1.push_back(0);
	vector<int> a2;
	a2.push_back(0);
	a2.push_back(0);
	a2.push_back(0);
	vector<int> a3;
	a3.push_back(0);
	a3.push_back(0);
	a3.push_back(1);
	A.push_back(a1);
	A.push_back(a2);
	A.push_back(a3);
	Solution s;
	
	cout<<s.shortestBridge(A);
	
	return 0;
}

