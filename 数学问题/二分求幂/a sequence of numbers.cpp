//九度教程第58题 
#include<iostream>
using namespace std;
#define mod 200907

int pow(long long dif,long long d){
	int ans=1;
	
	while(d!=0){
		if(d%2==1){
			ans*=dif;
			ans%=mod;
		}
		d/=2;
		dif*=dif;
		dif%=mod;
		
		
	}

	return ans;
}


int main(){
	long long a,b,c,d;
	int ans;
	cin>>a>>b>>c>>d;
	if(c-b==b-a){
		long long dif=c-b;
		//值得学习 
		ans=((((d-1)%mod)*(dif%mod))%mod+a%mod)%mod;
		
	}
	else{
		long long dif=c/b;
		ans=((a%mod)*pow(dif,d-1))%mod;
	} 
	
	cout<<ans;

	return 0;
}

