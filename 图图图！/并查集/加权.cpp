#include<iostream>
using namespace std;
double grade[100];
double jia[100]; 


int main(){
	double a,b,total=0;
	//����ɼ����Ȩ
	int n=1;
	cin>>b>>a;
	while(a!=0){
		grade[n]=a;
		jia[n++]=b;
		total+=b;
		cin>>b>>a;
	} 
	double ans=0;
	//�����Ȩ
	for(int i=1;i<=n;i++){
		ans+=grade[i]*(jia[i]/total);
	} 
	
	cout<<"���ļ�Ȩ�ǣ�"<<ans;

	return 0;
}

