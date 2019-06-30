#include<iostream>
using namespace std;

bool iss(int x){
	if(x==1){
		return false;
	}
	else{
		for(int i=2;i*i<=x;i++){
			if(x%i==0){
				return false;
			}
		}
	}
	return true;
} 


int main(){
	int x,y,xx,yy;
	cin>>xx>>yy;
	x=min(xx,yy);
	y=max(xx,yy);
	
	int ans=0;
	for(int i=x;i<=y;i++){
		if(iss(i)){
			ans++;
		}
	}
	cout<<ans;

	return 0;
}

