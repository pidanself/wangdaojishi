#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	//利用最小堆 
	int n,m;
	cin>>n>>m;
	while(n--!=0){
		priority_queue<int,vector<int>,greater<int> >que;
		int t;
		for(int i=0;i<m;i++){
			cin>>t;
			que.push(t);
		}
		for(int i=0;i<m-1;i++){
			cout<<que.top()<<" ";
			que.pop();
		}
		cout<<que.top()<<endl;
		que.pop();
	}
	
	//利用sort函数
	cin>>n>>m;
	while(n--!=0){
		vector<int> v;
		int t;
		for(int i=0;i<m;i++){
			cin>>t;
			v.push_back(t);
		}
		sort(v.begin(),v.end());
		
		for(int i=0;i<m-1;i++){
			cout<<v[i]<<" ";
		}
		cout<<(v[v.size()-1])<<endl;
	}
	

	return 0;
}

