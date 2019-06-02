//与Legal不同在于输出编号小的队伍在前 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//每个点的入度
int inD[501]={0}; 
	
//每个点指向的点 
vector<int> edge[501];

//入度为0的点队列
priority_queue<int, vector<int>, greater<int> > Q; 

int main(){

	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		edge[a].push_back(b);
		inD[b]++;
	}
	
	for(int i=0;i<n;i++){
		if(inD[i]==0){
			Q.push(i);
		}
	}
	int cnt=0;
	while(Q.empty()==false){
		int t=Q.top();
		cout<<t<<" ";
		Q.pop();
		for(int i=0;i<edge[t].size();i++){
			if(--inD[edge[t][i]]==0){
				Q.push(edge[t][i]);
			}
		} 
	}
	
}

