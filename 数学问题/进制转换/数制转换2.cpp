#include<iostream>
using namespace std;

int main(){
	int a,b;
	string n;
	cin>>a>>n>>b;
	int t=0;
	for(int i=0;i<n.size();i++){
		char tt=n[i];
		int x;
		if(tt>='0'&&tt<='9'){
			x=tt-'0';
		}
		else if(tt>='A'&&tt<='F'){
			x=tt-'A'+10;
		}
		else{
			x=tt-'a'+10;
		}
		t=t*a+x;
	}
	
	char ans[50];
	int index=0;
	do{
		int x=t%b;
		if(x>=0&&x<=9){
			ans[index++]='0'+x;
		}
		else{
			ans[index++]='A'+x-10;
		}
		t/=b;
	}while(t!=0);
	
	
	for(int i=index-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}

