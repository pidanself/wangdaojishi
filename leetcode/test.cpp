#include<iostream>
#include<vector>
#include<sstream>
#include<set>
using namespace std;

string i2s(int x){
	stringstream sstr;
	string str;
	sstr<<x;
	sstr>>str;
	return str;
}
set<string> S;

int main(){
	string a;
	int b=3;
	a+=i2s(b);
	b=2;
	a+=i2s(b);
	b=1;
	a+=i2s(b);
	//cout<<a;
	string bb;
	bb=a;
	bb[0]=a[1];
	bb[1]=a[0];
	//cout<<bb;
	
	S.insert("1234");
	S.insert("321");
	if(S.count(a)==0) cout<<a;
	if(S.count(bb)==0) cout<<bb;
}

