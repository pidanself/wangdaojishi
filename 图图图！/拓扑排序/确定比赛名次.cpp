//��Legal��ͬ����������С�Ķ�����ǰ 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//ÿ��������
int inD[501]={0}; 
	
//ÿ����ָ��ĵ� 
vector<int> edge[501];

//���Ϊ0�ĵ����
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

