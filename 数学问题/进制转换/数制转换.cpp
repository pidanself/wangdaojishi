#include<iostream>
using namespace std;
int s[1000]={0};
char an[100];
int main(){
	int a,b;
	char str[40];
	
	for(int i=0;i<10;i++){
		s[i+'0']=i;
	}
	char t='a',T='A';
	for(int i=0;i<=5;i++){
		s[t+i]=10+i;
		s[T+i]=10+i;
	}
	
	
	cin>>a>>str>>b;
	int ans=0;
	for(int i=0;str[i]!='\0';i++){
		ans=ans*a+s[str[i]];
	}
	int i=0;
	do{
		int t=ans%b;
		if(t<10){
			an[i++]=t+'0';
		}
		else{
			an[i++]=t%10+'a';
		}
		ans/=b;
	}while(ans!=0);
	i--;
	while(i!=-1){
		cout<<an[i--];
	}
	
	return 0;
}

