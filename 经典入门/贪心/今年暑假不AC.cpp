#include<iostream>
#include<algorithm>
using namespace std;

struct tv{
	int startTime;
	int endTime;
}; 

bool cmp(tv t1,tv t2){
	return t1.endTime<t2.endTime;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		tv t[n];
		for(int i=0;i<n;i++){
			scanf("%d %d",&t[i].startTime,&t[i].endTime);
		}
		sort(t,t+n,cmp);
		int ans=0;
		int tend=-1;
		for(int i=0;i<n;i++){
			if(t[i].startTime>=tend){
				ans++;
				tend=t[i].endTime;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

