#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<vector<int> > s;
	vector<int> t;
	t.push_back(1);
	t.push_back(2);
	t.push_back(3);
	
	s.push_back(t);
	
	for(int i=0;i<s[0].size();i++){
		cout<<s[0][i]<<endl;
	}

}

