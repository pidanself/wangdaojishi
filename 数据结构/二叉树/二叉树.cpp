#include<iostream>
#include<queue>
using namespace std;
queue <int> q;
int m,n;
int main(){
	int a=0;
	cin>>m>>n;
	a++;
	q.push(m);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		int l=2*t,r=2*t+1;
		if(l<=n){
			q.push(l);
			a++;
		}
		if(r<=n){
			q.push(r);
			a++;
		}
		
	}
	cout<<a;

	return 0;
}

