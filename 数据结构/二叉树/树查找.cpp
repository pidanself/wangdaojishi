#include<iostream>
#include<cmath> 
using namespace std;
int n,t[1001],ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int h;
	cin>>h;
	if(pow(2,h-1)>n){
		cout<<"EMPTY";
	}
	else{
		for(int i=pow(2,h-1);i<pow(2,h)&&i<=n;i++){
			cout<<t[i]<<" ";
		}
	}


	return 0;
}

