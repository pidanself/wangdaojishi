//二分求幂 不懂原理 只能先硬记 
#include<iostream>
using namespace std;

int main(){
	//计算a^b 
	int a,b;
	cin>>a>>b;
	int ans=1;
	while(b!=0){
		if(b%2==1){
			ans*=a;
			ans%=1000;
		}
		b=b/2;
		a*=a;
		a%=1000;
	}
	
	cout<<ans;


	return 0;
}

