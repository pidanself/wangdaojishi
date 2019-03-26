#include<iostream>
#include<cstring>
using namespace std;
int n,m; 
int b[201],s[201];
int main(){
	memset(b,0,sizeof(b));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		b[s[i]]++;
	}
	
	for(int i=0;i<n;i++){
		if(b[s[i]]>1){
			cout<<b[s[i]]-1<<endl;
		}
		else{
			cout<<"Beiju"<<endl;
		}
	}
	


	return 0;
}

