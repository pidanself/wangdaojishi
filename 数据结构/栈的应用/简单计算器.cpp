#include<iostream>
#include<stack>
using namespace std;
char str[300];
stack<int> ope;
stack<double> nu;
double ans[100];
int times=0;
int i=0;//作为字符串的指针 

//1代表i的优先级大于j,自己的优先级不会大于自己的
//同级的也不代表比对方大 
int m[5][5]={
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0 
}

void get(bool &on,int &retn,int reto){
	
}

//+1 -2 *3 /4 
int main(){
	bool on,num,op;
	scanf("%s",str);
	while(str[0]!='0'){
		
		while(i<strlen(str)){
			get(on,num,op); 
			if(on){
				while(!(ope.empty()==true||[op][ope.top()]==0)){
					
				}
				ope.push(op);
			}
			else{
				nu.push(num);
			}	
		}
		
		
		
		
		
		
		
		
		
		scanf("%s",str);
	}
	


	return 0;
}

