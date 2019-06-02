#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> edge[101];
queue<int> Q;

int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF&&n!=0){
		int inD[101]={0};
		for(int i=0;i<n;i++){
			inD[i]=0;
			edge[i].clear();
		}
		//读取边并初始化 
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
			cnt++;
			int t=Q.front();
			Q.pop();
			for(int i=0;i<edge[t].size();i++){
				if(--inD[edge[t][i]]==0){
					Q.push(edge[t][i]);
				}
			}
		}
		
		if(cnt==n) cout<<"YES";
		else cout<<"NO";
	}


}

