#include<iostream>
#include<queue>
#include<stack>
#include<sstream>
#include<math.h>
using namespace std;
char str[101];
int geti(char c){
	if(c=='+'){
		return 0;
	}
	else if(c=='-'){
		return 1;
	}
	else if(c=='*'){
		return 2;
	}
	else if(c=='/'){
		return 3;
	}
	else if(c=='^'){
		return 4;
	}
	else if(c=='('){
		return 5;
	}
	else if(c==')'){
		return 6;
	}
}


int pan[7][7]={
	1,1,0,0,0,0,1,
	1,1,0,0,0,0,1,
	1,1,1,1,0,0,1,
	1,1,1,1,0,0,1,
	1,1,1,1,1,0,1,
	0,0,0,0,0,0,2,
	0,0,0,0,0,0,1
};


double calculate(queue<string> post){
	stack<double> nums;
	while(!post.empty()){
		string temp=post.front();
		post.pop();
		if(temp=="+"||temp=="-"||temp=="/"||temp=="*"||temp=="^"){
			double num1,num2;
			num2=nums.top();
			nums.pop();
			num1=nums.top();
			nums.pop();
			if(temp=="+"){
				nums.push(num1+num2);
			}
			else if(temp=="-"){
				nums.push(num1-num2);
			}
			else if(temp=="/"){
				nums.push(num1/num2);
			}
			else if(temp=="*"){
				nums.push(num1*num2);
			}
			else{
				nums.push(pow(num1,num2));
			}
		}
		else if(temp=="#"){
			return nums.top();
		}
		else{
			stringstream sstr;
			double num;
			sstr<<temp;
			sstr>>num;
			nums.push(num);
		}
	}
}

//中缀表达式转后缀表达式 
queue<string> n2p(char str[]){
	queue<string> ans;
	stack<char> s;
	string nums="";
	for(int i=0;str[i]!='\0';i++){
		if(str[i]>='0'&&str[i]<='9'){
			nums=nums+str[i];
		}
		else{
			ans.push(nums);
			nums="";
			if(s.empty()){
				s.push(str[i]);
			}
			else{
				if(pan[geti(s.top())][geti(str[i])]==0){
					//当前运算符str[i]优先级高于s.top()
					s.push(str[i]); 
				}
				else{
					if(str[i]==')'&&s.top()=='('){
						s.pop();
					}
					else{
						string t="";
						t=t+s.top();
						ans.push(t);
						s.pop();
						i--;
					}
				}
			}
		}
	}
	if(nums!=""){
		ans.push(nums);
	}
	while(!s.empty()){
		string t="";
		t=t+s.top();
		ans.push(t);
		s.pop();
	}
	ans.push("#");
	return ans;
}


int main(){
	
	while(scanf("%s",str)!=EOF&&str[0]!='\0'){
//		nifixExpression//中缀表达式
//		postfixExpression//后缀表达式 

		//将中缀表达式转换为后缀表达式 
		queue<string> postfixExpression=n2p(str);
		queue<string> postfixExpression1=n2p(str);
		while(postfixExpression1.empty()==false){
			cout<<postfixExpression1.front();
			postfixExpression1.pop();
		}
		cout<<endl;
		//处理后缀表达式得出计算结果
		int ans=calculate(postfixExpression);
		cout<<ans<<endl;
	}


	//测试后缀表达式计算是否有问题：没问题 
//	queue<string> postfixExpression;
//	postfixExpression.push("3");
//	postfixExpression.push("4");
//	postfixExpression.push("/");
//	postfixExpression.push("10");
//	postfixExpression.push("+");
//	postfixExpression.push("#");
//	double ans=calculate(postfixExpression);
//	cout<<ans<<endl;
	
	
//	//测试中缀转后缀函数是否有问题：没问题 
//	char str[100];
//	scanf("%s",str);
//	queue<string> postfixExpression=n2p(str);
//	while(postfixExpression.empty()==false){
//		cout<<postfixExpression.front();
//		postfixExpression.pop();
//	}
	return 0;
}

