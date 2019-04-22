#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

class bigfloat{
	public:
		int sized=0,sizef=0;
		int digit[100]={0};
		int decimal[100]={0}; 
		
		//set the figure
		void set(char num[]){
			int i=0,len=strlen(num);
			while(num[i]!='.'){	
				i++;
			}
			int j=i+1;
			i--;
			for(;i>=0;i--){
				digit[sized++]=(int)(num[i]-'0');
			}
			
			for(;j<len;j++){
				decimal[sizef++]=(int)(num[j]-'0');
				
			}
		}
		
		//printf
		void output(){
			for(int i=sized-1;i>=0;i--){
				cout<<digit[i];
			}
			cout<<".";
			for(int i=0;i<sizef;i++){
				cout<<decimal[i];
			}
		}
		
		bigfloat operator + (const bigfloat a) const{
			bigfloat ret;
			//float
			int i=max(sizef,a.sizef);
			ret.sizef=max(sizef,a.sizef);
			int carry=0;
			for(;i>=0;i--){
				int t=decimal[i]+a.decimal[i]+carry;
				carry=t/10;
				ret.decimal[i]=t%10;
			}
			while(ret.decimal[ret.sizef]!=0){
				ret.sizef--;
			}
			//digital
			for(i=0;i<sized||i<a.sized;i++){
				int t=digit[i]+a.digit[i]+carry;
				carry=t/10;
				ret.digit[ret.sized++]=t%10;
			}
			if(carry!=0){
				ret.digit[ret.sized++]=carry;
			}
			return ret;
		}
};



int main(){
	char num[100],num1[100];
	cin>>num>>num1;
	bigfloat a,b;
	a.set(num);
	b.set(num1);
	a=a+b;
	a.output();


	return 0;
}

