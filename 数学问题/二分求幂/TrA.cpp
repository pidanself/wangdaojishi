//九度第59题，对矩阵进行二分求幂 
#include<iostream>
#include<stdlib.h>
using namespace std;
int A[10][10];

int **mulm(int **A,int **B,int n){
	int **t;
	t=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++){
		t[i]=(int *)malloc(n*sizeof(int));
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			t[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int tt=0;tt<n;tt++){
				int a=A[i][tt];
				int b=B[tt][j];
				t[i][j]+=a*b;
				t[i][j]%=9973;
			}
			
		}
	}
	return t;
} 

int **quickm(int **A,int k,int n){
	int **ans;
	ans=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++){
		ans[i]=(int *)malloc(n*sizeof(int));
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans[i][j]=A[i][j];
		}
	}
	k=k-1;
	while(k!=0){
		if(k%2==1){
			ans=mulm(ans,A,n);
		}
		
		k/=2;
		A=mulm(A,A,n);
	}
	
	return ans;
}

int main(){
	int **A;

	int n,k;
	cin>>n>>k;
	A=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++){
		A[i]=(int *)malloc(n*sizeof(int));
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	
	int **B;
	B=quickm(A,k,n);
//	B=mulm(A,A,n); 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=B[i][i];
		ans%=9973;
	}
	cout<<ans;
	return 0;
}

