#include<iostream>
#include<vector> 
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int ans=1;
        int len=nums.size()-1;
        if(len==0) return 0;
        int la[len]; //以下标为len的元素结尾的最长子序列
		for(int i=0;i<len;i++){
			la[i]=1;
		}
		for(int i=1;i<len;i++){
			for(int j=i-1;j>=0;j--){
				if(nums[j]<nums[i]&&(la[j]+1>la[i])){
					la[i]=la[j]+1;
					ans=max(ans,la[i]);
				}
			}
		}
		return ans;
    }
};


int main(){
	


}

