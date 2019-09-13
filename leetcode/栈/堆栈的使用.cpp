#include<iostream>
#include<stack>
using namespace std;



int main(){
	int num;
	while(scanf("%d",&num)!=EOF&&num!=0){
		stack<int> s;
		for(int i=0;i<num;i++){
			char t;
			cin>>t;
			if(t=='P'){
				int tnum;
				cin>>tnum;
				s.push(tnum);
			}
			else if(t=='O'){
				if(!s.empty()){
					s.pop();
				}
			}
			else if(t=='A'){
				if(s.empty()){
					cout<<'E'<<endl;
				}
				else{
					cout<<s.top()<<endl;
				}
			}
		}
		cout<<endl;
	} 

	return 0;
}

