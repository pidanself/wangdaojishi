#include<iostream>
using namespace std;
int eatCandy(int n){
	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	return eatCandy(n-1)+eatCandy(n-2);
}


int main(){
	int in;
	cin>>in;
	cout<<eatCandy(in);
	

}

