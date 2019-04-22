#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
class biginteger{
	public:
		int size=0;
		int digit[1000];
		
		void set(char num[]){
			int len=strlen(num);
			for(int i=len-1;i>=0;i--){
				digit[size++]=(int)(num[i]-'0');
			}
		}
		
		void output(){
			for(int i=size-1;i>=0;i--){
				cout<<digit[i];
			}
			cout<<endl;
		}
		
		bool operator < (const biginteger a) const{
			if(size!=a.size) return size<a.size;
			else{
				for(int i=size;i>=0;i--){
					if(digit[i]!=a.digit[i]) return digit[i]<a.digit[i];
				}
				return true;
			}
		}
	
	
	
};



int main(){
	int n;
	biginteger a[101];
	cin>>n;
	char num[101][1001];
	for(int i=0;i<n;i++){
		cin>>num[i];
		a[i].set(num[i]);
	}
	
	sort(a,a+n);
	
	for(int i=0;i<n;i++){
		a[i].output();
		
	}

	return 0;
}

