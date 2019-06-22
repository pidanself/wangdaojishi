#include<iostream>
using namespace std;





int main(){
	char s[]="ShanghaiChina";
	int num=0,i;
	for(i =0;s[i]!='\0';i++){
		if(s[i]=='h'||s[i]=='n'){
			num++;
		}
	}
	cout<<num;
	return 0;
}

