#include<iostream>
using namespace std;
//完成两个1000位以内的大数相加

struct bignumber{
	//一位代表一个数字 
	int digit[1200]={0};
	int size=0;
	
	void set(string s){
		for(int i=s.size()-1;i>=0;i--){
			digit[size++]=s[i]-'0';
		}
	}
	
	//输出
	void output(){
		for(int i=size-1;i>=0;i--){
			cout<<digit[i];
		}
		cout<<endl;
	} 
}; 
 
bignumber add(bignumber a,bignumber b){
	bignumber ans;
	int res=0;
	for(int i=0;i<a.size||i<b.size;i++){
		int t=a.digit[i]+b.digit[i]+res;
		res=t/10;
		ans.digit[ans.size++]=t%10;
	}
	if(res!=0){
		ans.digit[ans.size++]=res;
	}
	return ans;
} 

int main(){
	string s1,s2;
	cin>>s1>>s2;
	bignumber a,b,c;
	a.set(s1);
	b.set(s2);
	c=add(a,b);
	c.output();

	return 0;
}

