#include<iostream>
using namespace std;

//ԭ����Ҫ��һ����� 
//https://leetcode-cn.com/problems/edit-distance/ 
/*
����1����� word1[0..i-1] �� word2[0..j-1] �ı任��Ҫ���� k ������ word1[0..i] �� word2[0..j] �ı任��Ҫ�����أ�

����ʹ�� k ������ word1[0..i-1] �任�� word2[0..j-1]������ k �����ٰ� word1[i] �ĳ� word2[j]�������ˡ���� word1[i] == word2[j]��ʲôҲ��������һ������ k ����������Ҫ�޸ģ�һ������ k + 1 ����

����2����� word1[0..i-1] �� word2[0..j] �ı任��Ҫ���� k ������ word1[0..i] �� word2[0..j] �ı任��Ҫ���ļ����أ�

���Ⱦ��� k ������ word1[0..i-1] �任�� word2[0..j]�����ĵ� k �����ٰ� word1[i] ɾ����������word1[0..i] ����ȫ����� word2[0..j] �ˡ�һ�� k + 1 ����

����3����� word1[0..i] �� word2[0..j-1] �ı任��Ҫ���� k ������ word1[0..i] �� word2[0..j] �ı任��Ҫ���ļ����أ�

���Ⱦ��� k ������ word1[0..i] �任�� word2[0..j-1]�����ĵ� k �������������ٲ���һ���ַ� word2[j], word1[0..i] ����ȫ����� word2[0..j] �ˡ�

��������������������word1[0..i] �任�� word2[0..j] ��Ҫ�������ֶΣ����ĸ������٣������ĸ���
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

