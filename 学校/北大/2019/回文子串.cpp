#include<iostream>
using namespace std;

bool ish(string s,int i,int j){
	while(i<=j){
		if(s[i]!=s[j]){
			return false;
		}
		else{
			i++;
			j--;
		}
	}
	return true;
}


int main(){
	string s;
	cin>>s;
	int l=s.length();
	for(int i=2;i<=l;i++){
		for(int j=0;j+i-1<l;j++){
			if(ish(s,j,j+i-1)){
				cout<<s.substr(j,i)<<endl;
			}
			else{
				continue;
			}
		}
	}

	return 0;
}

