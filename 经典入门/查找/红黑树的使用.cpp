#include<iostream>
#include<map>
using namespace std;
struct s{
	string num;
	char name[20];
	char sex[20];
	int age;
};

map <string,const s*> m;

int main(){
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		s *t=new s;
		cin>>t->num>>t->name>>t->sex>>t->age;
		m.insert(make_pair(t->num,t));
	}
	map <string,const s*>::iterator iter;
	int mm;
	cin>>mm;
	string nu[mm];
	for(int i=0;i<mm;i++){
		cin>>nu[i];
	}
	for(int i=0;i<mm;i++){
		iter=m.find(nu[i]);
		cout<<iter->second->num<<" "<<iter->second->name<<" "<<iter->second->sex<<" "<<iter->second->age<<endl;
	}

	return 0;
}

