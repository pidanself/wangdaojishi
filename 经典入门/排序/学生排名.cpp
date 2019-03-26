#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct S{
	int age;
	double grade;
	char name[101];
	bool operator < (const S &b) const{
		if(grade!=b.grade) return grade<b.grade;
	
		int i=strcmp(name,b.name);
	
		if(i!=0) return i<0;
	
		return age<b.age;
	}
}; 

S s[1000];

bool cmp(S a,S b){
	if(a.grade!=b.grade) return a.grade<b.grade;
	
	int i=strcmp(a.name,b.name);
	
	if(i!=0) return i<0;
	
	return a.age<b.age;

}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].name;
		cin>>s[i].age;
		cin>>s[i].grade;
	}
	
	sort(s,s+n);
	
	for(int i=0;i<n;i++){
		cout<<s[i].name<<" "<<s[i].age<<" "<<s[i].grade<<endl;

	}

	return 0;
}

