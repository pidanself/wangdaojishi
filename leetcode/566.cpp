#include<iostream>
#include<vector> 
using namespace std;
vector<vector<int> > a;
vector<int> b;
vector<int> c;

int main(){
	a.push_back(b);
	a.push_back(c);
	cout<<a.size()<<endl;
	a[0].push_back(1);
	cout<<a[0].size()<<endl;
	cout<<a[1].size()<<endl;
	


	return 0;
}

