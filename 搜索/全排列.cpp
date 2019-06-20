#include<iostream>
#include<algorithm> 

#include <string.h>
using namespace std;

int main(){

	string s;
	//scanf("%s",&s[0]);
	char c[7];
	scanf("%s",c);
	int len=strlen(c);
	do{
		printf("%s\n",c);
	}while(next_permutation(c,c+len));
	
}

