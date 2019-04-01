#include<iostream>
#include<stack> 
#include<cstring>
using namespace std;
stack<int> s;

//ÊäÈë×Ö·û´®
char str[100];
char ans[100]; 

int main(){
	while(scanf("%s",str)!=EOF){
		int i=0;
		for(;i<strlen(str);i++){
			if(str[i]=='('){
				s.push(i);
				ans[i]=' ';
			}
			else if(str[i]==')'){
				if(s.empty()==false){
					s.pop();
					ans[i]=' ';
				}
				else{
					ans[i]='?';
				}
			}
			else{
				ans[i]=' ';
			}
		}
		ans[i]=0; 
		while(s.empty()==false){
			ans[s.top()]='$';
			s.pop();
		}
		puts(str);
		puts(ans);
		
	}


	return 0;
}

