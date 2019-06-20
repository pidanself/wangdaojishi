#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;

class Solution {
public:
	map<int,int> mem[21];
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums,0,nums[0],S)+dfs(nums,0,-nums[0],S);
    }
    
    
    int dfs(vector<int>& nums,int n,int total,int tar){
    	if(mem[n].find(total)!=mem[n].end()){
    		return mem[n][total];
		}
    	
    	if(n==nums.size()-1){
    		if(total==tar){
    			return 1;
			}
			return 0;
		}
		
		mem[n][total]=dfs(nums,n+1,total+nums[n+1],tar)+dfs(nums,n+1,total-nums[n+1],tar);
		return mem[n][total];
	}
};


int main(){



}

