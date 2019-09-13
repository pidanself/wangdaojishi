#include<iostream>
#include<stack> 
using namespace std;

int main(){
	stack<char> s;
	char str[110];//±£´æÊäÈë×Ö·û´®
	char ans[110];//±£´æÊä³ö×Ö·û´®
	
	while(scanf("%s",str)!=EOF){
		int i;
		for(i=0;str[i]!='\0';i++){
			if(str[i]=='('){
				s.push(i);
				ans[i]=' ';
			}
			else if(str[i]==')'){
				if(s.empty()){
					ans[i]='?';
				}
				else{
					s.pop();
					ans[i]=' ';
				}
			}
			else{
				ans[i]=' ';
			}
		}
		while(!s.empty()){
			int x=s.top();
			s.pop();
			ans[x]='$';
		}
		ans[i]='\0';
		cout<<str;
		 cout<<ans;
	} 
	return 0;
}

