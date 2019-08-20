#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Solution {
public:
    bool isBipartite(vector<vector<int> >& graph) {
        //0未染 1 2 各代表一种状态 
		int color[101]={0};

		for(int i=0;i<graph.size();i++){
			if(color[i]==0){
				v.push(i);
				color[i]=1;
				while(!v.empty()){
					int now=v.front();
					//应该染成的颜色 
					int shouldColor;
					if(color[now]==1){
						shouldColor=2;
					}
					else{
						shouldColor=1;
					}
					for(int i=0;i<graph[now].size();i++){
						int j=graph[now][i];
						if(color[j]==0){
							color[j]=shouldColor;
							v.push(j);
						}
						else{
							if(shouldColor!=color[j]){
								return false;
							}
						}
					}
					v.pop();
				}
			}
		}
		return true; 
    }
private:
	queue<int> v;
};

int main(){





	return 0;
}

