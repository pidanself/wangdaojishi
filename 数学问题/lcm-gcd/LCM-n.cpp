#include<iostream>
using namespace std;

int gcd(int a,int b){
	
	return b?gcd(b,a%b):a;
}


int main(){
	int t,ans=1;
	while(cin>>t){
		if(cin.get()=='\n'){
			break;
		}
		ans=ans*t/(gcd(ans,t));
	}
	
	cout<<ans;
	return 0;
}

