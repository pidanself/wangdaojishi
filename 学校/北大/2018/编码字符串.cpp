#include<iostream>
using namespace std;
int nums[200]={0};

int main(){
	string s;
	cin>>s;
	int start=0,end=0;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>=97&&s[i]<=122){
			continue;
		}
		else{
			s[i]=s[i]+32;
		}
	}
	while(start<s.size()){
		while(end<s.size()&&s[end]==s[start]){
			end++;
		}
		printf("(%c,%d)",s[start],end-start);
		start=end;
	}
	
	
	
	
	
	
	
	
//	for(int i=0;i<s.size();i++){
//		char t=s[i];
//		nums[t]++;
//	}
//	for(int i=97;i<=122;i++){
//		if(nums[i]!=0){
//			char t=(char)i;
//			printf("(%c,%d)",t,nums[i]);
//		}
//	}
	
	return 0;
}

