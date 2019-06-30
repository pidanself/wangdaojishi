#include<iostream>
using namespace std;
char g[81][81];

int main(){
	int n;
	char b[2];
	cin>>n>>b[0]>>b[1];
	
	for(int k=1;k<=n;k++){
		char c=b[k%2];
		for(int i=k,j=k;j<=n-k+1;j++){
			g[i][j]=c;
		}
		for(int i=k,j=k;i<=n-k+1;i++){
			g[i][j]=c;
		}
		for(int i=n-k+1,j=k;j<=n-k+1;j++){
			g[i][j]=c;
		}
		for(int i=k,j=n-k+1;i<=n-k+1;i++){
			g[i][j]=c;
		}
	}
	if(n!=1){
		g[1][1]=' ';
		g[1][n]=' ';
		g[n][1]=' ';
		g[n][n]=' ';		
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<g[i][j];
		}
		cout<<endl;
	}
	
	

	return 0;
}

