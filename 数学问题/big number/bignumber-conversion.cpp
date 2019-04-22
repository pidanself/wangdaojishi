#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;

//define bignumber class
class biginteger{
	public:
		//initialize
		int size=0;
		int digit[10000]={0};
		//set your number according to input char
		void set(char num[]){
			int len=strlen(num);
			
			for(int i=len-1,j=0,t=0,c=1;i>=0;i--){
				t+=(int)(num[i]-'0')*c;
				c*=10;
				j++;
				if(i==0||j==4){
					digit[size++]=t;
					t=0;
					c=1;
					j=0;
				}
			}
		}
		
		//printf
		void output(){
			
			for(int i=size-1;i>=0;i--){
				if(i!=size-1) printf("%04d",digit[i]);
				else printf("%d",digit[i]);
				
			}
		}
		
		//overload operator
		
		//*
		biginteger operator * (int x) const{
			biginteger ret;
			int carry=0;
			for(int i=0;i<size;i++){
				int t=carry+digit[i]*x;
				carry=t/10000;
				ret.digit[ret.size++]=t%10000;
			}
			if(carry!=0){
				ret.digit[ret.size++]=carry;
			}
			return ret;
		}
		
		//+
		biginteger operator + (const biginteger a) const{
			biginteger ret;
			int carry=0;
			for(int i=0;i<size||i<a.size;i++){
				int t=carry+digit[i]+a.digit[i];
				carry=t/10000;
				ret.digit[ret.size++]=t%10000;
			}
			if(carry!=0){
				ret.digit[ret.size++]=carry;
			}
			return ret;
		}
		
		//division
		biginteger operator / (int x) const{
			biginteger ret;
			ret.size=size;
			int carry=0;
			for(int i=size-1;i>=0;i--){
				int t=(digit[i]+carry*10000)/x;
				int r=(digit[i]+carry*10000)%x;
				carry=r;
				ret.digit[i]=t;
			}
			int i=size;
			while(ret.digit[i]==0){
				i--;
			}
			ret.size=i+1;
			
			return ret;
		} 
		
		//%
		int operator % (int x) const{
			int carry=0;
			for(int i=size-1;i>=0;i--){
				int t=(digit[i]+carry*10000)/x;
				int r=(digit[i]+carry*10000)%x;
				carry=r;
			}
			return carry;
		}
}; 



int main(){
	int m,n;
	vector <char> result;
	cin>>m>>n;
	
	char num[10000];
	cin>>num;
	biginteger a,b;
	b.set("1");
	int len=strlen(num);
	//convert to 10,store in a
	for(int i=len-1;i>=0;i--){
		int t;
		if(num[i]>='0'&&num[i]<='9'){
			t=(int)(num[i]-'0');
		}
		else{
			t=(int)(num[i]-'A')+10;
		}
		a=a+(b*t);
		b=b*m;
	}

	//convert to n
	while(a.size!=0){
		int t=a%n;
		char tt;
		if(t<10&&t>-1) tt=(char)(t+'0');
		else tt=(char)(t-10+'a');
		a=a/n;
		result.push_back(tt);
	}
	
	for(int i=result.size()-1;i>=0;i--){
		cout<<result[i];
	}
	return 0;
}

