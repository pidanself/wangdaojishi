#include<iostream>
#include<sstream>
using namespace std;

int s2i(string s){
	stringstream sstr;
	int x;
	sstr<<s;
	sstr>>x;
	return x;
}
int main(){
	string a="1234";
	int ans=s2i(a.substr(0,2));
	cout<<ans;

	return 0;
}

