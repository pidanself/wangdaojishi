#include<iostream>
#include<queue>
using namespace std;
int t;
int times,ans[100]={0};
priority_queue<int,vector<int>,greater<int> > m;

int main(){
	int n;
	cin>>n;
	while(n!=0){
		for(int i=0;i<n;i++){
			cin>>t;
			m.push(t);
		}
		
		for(int i=0;i<n-1;i++){
			int a,b;
			a=m.top();
			m.pop();
			b=m.top();
			m.pop();
			ans[times]+=a+b;
			m.push(a+b);
		}
		
		times++;
		m.pop();
		cin>>n;
	}
	
	for(int i=0;i<times;i++){
		cout<<ans[i]<<endl;
	}


	return 0;
}

