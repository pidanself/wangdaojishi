#include<iostream>
using namespace std;

int main(){
	int ans[100]={0};
	int i=0;
	int a,b,c;
	cin>>a>>b>>c;
	a=a+b;
	do{
		int t=a%c;
		ans[i++]=t;
		a/=c;
	}while(a!=0);
	i--;
	while(i!=-1){
		cout<<ans[i--];
	}

	return 0;
}

