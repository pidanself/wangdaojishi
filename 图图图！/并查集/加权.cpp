#include<iostream>
using namespace std;
double grade[100];
double jia[100]; 


int main(){
	double a,b,total=0;
	//输入成绩与加权
	int n=1;
	cin>>b>>a;
	while(a!=0){
		grade[n]=a;
		jia[n++]=b;
		total+=b;
		cin>>b>>a;
	} 
	double ans=0;
	//计算加权
	for(int i=1;i<=n;i++){
		ans+=grade[i]*(jia[i]/total);
	} 
	
	cout<<"您的加权是："<<ans;

	return 0;
}

