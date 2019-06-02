//这道题与之前不同之处在于选手为名字，要对字符串有所处理方能计算 
#include<vector>
#include<map>
#include<iostream>
#include<queue>
using namespace std;


//每个选手（点）的入度
int inD[1001]={0};
//每个选手的指向
vector<int> edge[1001];
//入度为0的队列
queue<int> Q;

map<string,int> ma; 

int main(){
	int index=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		string a,b;
		int indexa,indexb;
		cin>>a>>b;
		if(ma.find(a)!=ma.end()){
			indexa=ma[a];
		}
		else{
			indexa=index++;
			ma[a]=indexa;
		}
		
		if(ma.find(b)!=ma.end()){
			indexb=ma[b];
		}
		else{
			indexb=index++;
			ma[b]=indexb;
		}
		
		edge[indexa].push_back(indexb);
		inD[indexb]++;
	}
	
	int cntt=0;
	for(int i=0;i<n;i++){
		if(inD[i]==0){
				Q.push(i);
				cntt++;
			}
	}
	if(cntt!=1){
		cout<<"NO";
		return 0;
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

