#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int m=1;
        ans=s[0];
        for(int i=0;i<s.length();i++){
        	for(int j=i+1;j<s.length();j++){
        		string tmp=s.substr(i,j-i+1);
        		string tmpr=tmp;
        		reverse(tmpr.begin(),tmpr.end());
        		if(tmpr==tmp){
        			if(j-i+1>m){
        				ans=tmp;
        				m=j-i+1;
					}
        			continue;
				}
			
			}
		}
        
		return ans;
    }
};


int main(){
	Solution s;
	cout<<s.longestPalindrome("babad");


}

