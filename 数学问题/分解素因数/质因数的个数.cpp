#include<iostream>
using namespace std;
//true为非素数，false为素数 
bool mark[100001];
int prime[100001];
int primesize;

void init(){
	for(int i=0;i<100001;i++){
		mark[i]=false;
	}
	primesize=0;
	for(int i=2;i<100001;i++){
		if(mark[i]) continue;
		prime[primesize++]=i;
		if(i>=1000) continue;
		for(int j=i*i;j<100001;j+=i){
			mark[j]=true;
		}
	}
	return ; 
}


int main(){
	int n;
	cin>>n;
	int ansPrime[30];
	int ansSize=0;
	int ansNum[30];
	init();
	
	for(int i=0;i<primesize;i++){
		if(n%prime[i]==0){
			ansPrime[ansSize]=prime[i];
			ansNum[ansSize]=0;
			while(n%prime[i]==0){
				ansNum[ansSize]++;
				n/=prime[i];
			}
			ansSize++;
			if(n==1) break;
		}
	}
	
	if(n!=1){
		ansPrime[ansSize]=n;
		ansNum[ansSize++]=1;
	}
	int ans=0;
	for(int i=0;i<ansSize;i++){
		ans+=ansNum[i];
	}
	cout<<ans; 
	return 0;
}

