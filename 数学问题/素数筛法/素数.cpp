//P79 
#include<iostream>
using namespace std;
int n=0;
bool mark[10001]={0};//0代表是素数


 
int main(){
	cin>>n;
	for(int i=2;i<n+1;i++){
		int j=2;
		if(!mark[i]){
			while(i*j<=n){
				mark[i*j]=true;
				j++;
			}
			if(i%10==1){
				cout<<i<<" ";	
			}
				
		}
		
	} 
	


	return 0;
}

