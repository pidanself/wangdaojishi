#include<iostream>
#include<algorithm>
using namespace std;
struct t{
	int start;
	int end;
	
};

bool cmp(t a,t b){
	return a.end<b.end;
}

int main(){
	int n,times=0;
	int ans[100]={0};
	cin>>n;
	t f[100];
	while(n!=0){
		for(int i=0;i<n;i++){
			cin>>f[i].start>>f[i].end;
		}
		sort(f,f+n,cmp);
		int q=f[0].end;
		ans[times]++;
		for(int i=1;i<n;i++){
			if(f[i].start>=q){
				ans[times]++;
				q=f[i].end;
			}
		} 
		times++;
		cin>>n;
		
	}
	
	for(int i=0;i<times;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}

