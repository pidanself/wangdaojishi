#include<iostream>
using namespace std;
bool mark[10010]={0};//0代表是素数 


int main(){
	int k;
	cin>>k;
		
	int j=0,i=2;
		
		for(i;i<1000;i++){
			if(!mark[i]){
				j++;
				if(j==k){
					cout<<i;
					break;
				}
				int b=2;
				while(b*i<10000){
					mark[b*i]=1;
					b++;
				}
			}	
		}

	

	return 0;
}

