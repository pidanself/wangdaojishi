#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
//big number class
class biginteger{
	public:
		int size=0;
		int digit[1000];
		
		void set(char num[]){
			int len=strlen(num);
			for(int i=len-1,j=0,t=0,c=1;i>=0;i--){
				t+=c*(int)(num[i]-'0');
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
		
		void output(){
			for(int i=size-1;i>=0;i--){
				if(i!=size-1) printf("%04d",digit[i]);
				else printf("%d",digit[i]);
			}
		}
	
	
	
}; 
biginteger subb(biginteger a,biginteger b){
	biginteger t;
	int bit=0;
	for(int i=0;i<a.size;i++){
		t.digit[t.size]=a.digit[i]-b.digit[i]-bit;
		if(t.digit[t.size]<0){
			bit=1;
			t.digit[t.size]=t.digit[t.size]+10000;
		}
		else{
			bit=0;
		}
		t.size++;
	}
	while(t.digit[t.size-1]==0){
		if(t.size==1){
			break;
		}
		t.size--;
	}
	return t;
}

int cmp(biginteger a,biginteger b){
	if(a.size>b.size){
		return 0;
	}
	else if(a.size<b.size){
		return -1;
	}
	else{
		for(int i=a.size-1;i>=0;i--){
			if(a.digit[i]>b.digit[i]){
				return 0;
			}
			else if(a.digit[i]<b.digit[i]){
				return -1;
			}
		}
		return 0;
	}
}


biginteger sub(biginteger a,biginteger b){
	biginteger t;
	
	if(cmp(a,b)==0){
		t=subb(a,b);
	}
	else{
		t=subb(b,a);
		t.digit[t.size-1]=-t.digit[t.size-1];
	}
	
	return t;
}

int main(){
	biginteger a,b,c;
	char num[1000],num2[1000];
	cin>>num>>num2;
	a.set(num);
	b.set(num2);
	
	c=sub(a,b);
	c.output();

	return 0;
}

