#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int p=n*n;
	do{
		int t=n%10;
		int tt=p%10;
		if(t==tt){
			p=p/10;
			n=n/10;
		}
		else {
			cout<<"NO";
			return 0;
		}
	}while(n!=0);
	cout<<"YES";

	return 0;
}

