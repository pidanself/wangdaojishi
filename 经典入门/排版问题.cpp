#include<iostream>
using namespace std;

int main(){
	int h=0;
	cin>>h;
	int max=2*(h-1)+h;
	
	for(int i=1;i<=h;i++){
		for(int j=0;j<(max-2*(i-1)-h);j++){
			cout<<" ";
		}
		for(int j=0;j<(h+2*(i-1));j++){
			cout<<"*";
		}
		cout<<endl;
	} 


	return 0;
}

