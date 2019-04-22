#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string.h>
using namespace std;
class biginteger{
	public:
		int digit[1000]={0};
		int size=0;
	public:
		//以下是我的冗余代码 
		void set(char num[]){
			int cir=(strlen(num))/4;
			int rem=(strlen(num))%4;
			int a=0;
			if(rem!=0){
				a=1;
			}
			for(int i=cir-1;i>=0;i--){
				int ans=0,t=4*i+rem;
				ans+=(int)(num[t]-'0')*1000;
				ans+=(int)(num[t+1]-'0')*100;
				ans+=(int)(num[t+2]-'0')*10;
				ans+=(int)(num[t+3]-'0');
				digit[i+a]=ans;
			}
			if(rem!=0){
				int ans=0;
				for(int i=0;i<rem;i++){
					
					ans+=(int)(num[i]-'0')*pow(10,rem-i-1);
				}
				digit[0]=ans;
			}
			size=cir+a;
		}
		//以下是课本的优美代码
		void setn(char num[]){
			int len=strlen(num);
			//i表示从数组最高位开始遍历，j控制
			//每四个字符转换为一个数组存入数组
			//c控制当前位的权重,1,10,100,1000
			//t存储临时结果 
			for(int i=len-1,j=0,c=1,t=0;i>=0;i--){
				t+=(num[i]-'0')*c;
				c*=10;
				j++;
				if(j==4||i==0){
					digit[size++]=t;
					j=0;
					c=1;
					t=0;
				}
			}
			
		} 
		//以下是我的冗余输出代码 
		void output(){
			for(int i=0;i<size;i++){
				
				
				if(digit[i]==0){
					cout<<"0000";
				}
				else{
					int nums=(int)log10(digit[i])+1;
					if(nums==1){
					cout<<"000"<<digit[i];
					}
					else if(nums==2){
						cout<<"00"<<digit[i];
					}
					else if(nums==3){
						cout<<"0"<<digit[i];
					}
					else{
						cout<<digit[i];	
					}	
				}
				
			}
		}
		//以下是课本上的优美代码
		void outputt(){
			for(int i=size-1;i>=0;i--){
				if(i!=size-1) printf("%04d",digit[i]);
				else printf("%d",digit[i]);
			}
		} 
		 
};

biginteger add(biginteger a,biginteger b){
	biginteger t;
	int carry=0;
	for(int i=0;i<a.size||i<b.size;i++){
		int tt=a.digit[i]+b.digit[i]+carry;
		carry=tt/10000;
		t.digit[t.size++]=tt%10000;
	}
	if(carry!=0){
		t.digit[t.size++]=carry;
	}
	return t;
}

int main(){
	biginteger a,b;
	char num[100],num1[100];
	cin>>num>>num1;
	a.setn(num);
	b.setn(num1);
	biginteger c;
	c=add(a,b);
	c.outputt();

	return 0;
}

