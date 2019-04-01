//√‘’Œ 
#include<iostream>
#include<algorithm>
using namespace std;
int y[101];
int ans[101]={0};
float anss[101]={0};

int main(){
	int c,n,v,w;
	cin>>c;
	for(int i=0;i<c;i++){
		cin>>n>>v>>w;
		for(int j=0;j<n;j++){
			cin>>y[j];
		}
		sort(y,y+n);
		for(int j=0;j<n;j++){
			float t=(ans[i]*anss[i]+v*y[j])/(ans[i]+v);
			if(t>w){
				break;
			}
			anss[i]=t;
			ans[i]=ans[i]+v;
		}
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	for(int i=0;i<c;i++){
		cout<<ans[i]<<" "<<anss[i]/100<<endl;
		
	} 

	return 0;
}

