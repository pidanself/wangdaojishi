#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		q.push(t);
	}
	while(!q.empty()){
		int a,b;
		a=q.top();
		q.pop();
		if(q.empty()) break;
		else{
			b=q.top();
			q.pop();
			ans+=a+b;
			q.push(a+b);
		}
	}
	cout<<ans;
	return 0;
}

