//Goldbach's Conjecture(九度教程第53 题)
//https://blog.csdn.net/qq_37053885/article/details/88042102
#include<iostream>
#include<vector>
#define N 32768
using namespace std;
bool mark[N+1]={0};//0代表素数
vector<int> index;


int main(){
	
	mark[1]=1;
	int e,ans=0;
	cin>>e;
	for(int i=2;i<e;i++){
		if(!mark[i]){
			index.push_back(i);
			int b=2;
			while(i*b<e){
				mark[i*b]=1;
				b++;
			}
		}
	}
	
	for(int i=0;i<index.size();i++){
		int t=e-index[i];
		if(!mark[t]){
			mark[t]=1;
			mark[index[i]]=1;
			ans++;
		}
	}
	cout<<ans;

	return 0;
}

