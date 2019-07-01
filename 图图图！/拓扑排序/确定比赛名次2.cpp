#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501];
int indegree[501];
priority_queue<int,vector<int>,greater<int> > q;

int main(){
	int n,m;
	cin>>n>>m;
	//初始化
	for(int i=1;i<=n;i++){
		edge[i].clear();
		indegree[i]=0; 
	} 
	
	//输入边
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		indegree[b]++;
		edge[a].push_back(b);
	} 
	
	//寻找所有入度为0的边
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	} 
	
	while(!q.empty()){
		int t=q.top();
		q.pop();
		for(int i=0;i<edge[t].size();i++){
			if(--indegree[edge[t][i]]==0){
				q.push(edge[t][i]);
			}
		}
		cout<<t<<" ";
	}

	return 0;
}

