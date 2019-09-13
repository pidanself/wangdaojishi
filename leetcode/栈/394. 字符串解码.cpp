#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
    	int len=s.size();
    	string res="";
    	int num=0;
    	stack<int> nums;
    	stack<string> strs;
    	for(int i=0;i<len;i++){
    		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
    			res+=s[i];
			}
			else if(s[i]>='0'&&s[i]<='9'){
				num=num*10+s[i]-'0';
			}
			else if(s[i]=='['){
				strs.push(res);
				res="";
				nums.push(num);
				num=0;
			}
			else if(s[i]==']'){
				int times=nums.top();
				nums.pop();
				for(int j=0;j<times;j++){
					strs.top()+=res;
				}
				res=strs.top();
				strs.pop();
			}
		}
    	return res;
    }
};

int main(){


	return 0;
}

