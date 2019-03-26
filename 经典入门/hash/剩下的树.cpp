#include<iostream>
#include<cstring>
using namespace std;
bool t[10001]={0};
int ans[100]={0};
int main(){
	int n,m;
	int times=0;
	while(scanf("%d %d",&n,&m)!=EOF&&m!=0&&n!=0){
		int l,r;
		for(int i=0;i<m;i++){
			cin>>l>>r;
			for(int j=l;j<=r;j++){
				t[j]=1;
			}
		}
		for(int i=0;i<n+1;i++){
			if(t[i]==0){
				ans[times]++;
			}
		}
		times++;
		memset(t,0,sizeof(t));
	} 
	
	for(int i=0;i<times;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}

