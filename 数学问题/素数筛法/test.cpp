#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[i+1]){
                ans++;
                if(ans>1){
                    return false;
                }
            }
        }
        return true;
    }
};



int main(){



	return 0;
}

