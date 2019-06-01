#include<iostream>
using namespace std;

//原理需要进一步理解 
//https://leetcode-cn.com/problems/edit-distance/ 
/*
问题1：如果 word1[0..i-1] 到 word2[0..j-1] 的变换需要消耗 k 步，那 word1[0..i] 到 word2[0..j] 的变换需要几步呢？

答：先使用 k 步，把 word1[0..i-1] 变换到 word2[0..j-1]，消耗 k 步。再把 word1[i] 改成 word2[j]，就行了。如果 word1[i] == word2[j]，什么也不用做，一共消耗 k 步，否则需要修改，一共消耗 k + 1 步。

问题2：如果 word1[0..i-1] 到 word2[0..j] 的变换需要消耗 k 步，那 word1[0..i] 到 word2[0..j] 的变换需要消耗几步呢？

答：先经过 k 步，把 word1[0..i-1] 变换到 word2[0..j]，消耗掉 k 步，再把 word1[i] 删除，这样，word1[0..i] 就完全变成了 word2[0..j] 了。一共 k + 1 步。

问题3：如果 word1[0..i] 到 word2[0..j-1] 的变换需要消耗 k 步，那 word1[0..i] 到 word2[0..j] 的变换需要消耗几步呢？

答：先经过 k 步，把 word1[0..i] 变换成 word2[0..j-1]，消耗掉 k 步，接下来，再插入一个字符 word2[j], word1[0..i] 就完全变成了 word2[0..j] 了。

从上面三个问题来看，word1[0..i] 变换成 word2[0..j] 主要有三种手段，用哪个消耗少，就用哪个。
*/
int dp[1000][1000];
class Solution {
public:
    int minDistance(string word1, string word2) {
        
		int i1=word1.length(),i2=word2.length();
		for(int i=0;i<=i1;i++){
			for(int j=0;j<=i2;j++){
				if(i==0){
					dp[i][j]=j;
				}
				else if(j==0){
					dp[i][j]=i;
				}
				else{
					int d1,d2,d3;
					d1=(word1[i-1]==word2[j-1])?(dp[i-1][j-1]):(dp[i-1][j-1]+1);
					d2=dp[i-1][j]+1;
					d3=dp[i][j-1]+1;
					int ans;
					ans=min(d1,d2);
					ans=min(ans,d3);
					dp[i][j]=ans;
				}
			}
		
		}
		int t=dp[i1][i2]; 
		return t; 
    }
};


int main(){
	Solution s;
	cout<<s.minDistance("horse","ros");
	return 0;
}

