#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct student{
	char no[20];
	char name[50];
	char sex[5];
	int age;
};

bool cmp(student s1,student s2){
	return strcmp(s1.no,s2.no)<0;
}


int main(){
	int n;
	cin>>n;
	student s[n];
	for(int i=0;i<n;i++){
		cin>>s[i].no>>s[i].name>>s[i].sex>>s[i].age;
		
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		cout<<s[i].no<<s[i].name<<s[i].sex<<s[i].age<<endl;
	}
	
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		char nno[20];
		cin>>nno;
		int start=0,end=n-1;
		int mid;
		int ans=-1;
		while(start<=end){
			mid=(start+end)/2;
			if(strcmp(nno,s[mid].no)==0){
				ans=mid;
				break;
			}
			else if(strcmp(nno,s[mid].no)<0){
				end=mid-1;
			}
			else{
				start=mid+1;
			}
		}
		if(ans==-1){
			cout<<"No Answer!"<<endl;
		}
		else{
			cout<<s[ans].no<<endl;
		}
	}
	return 0;
}

