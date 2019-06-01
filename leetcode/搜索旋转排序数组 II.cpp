#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
    }
    
    
    int binaryfind(vector<int>& nums,int low,int high,int target){
    	int l,h;
    	l=low,h=high;
    	int mid;
    	while(low<=high){
    		mid=(low+high)/2;
    		if(nums[mid]==target){
    			return mid;
			}
			else if(nums[mid]>target){
				//左走
				h=mid-1; 
			}
			else{
				l=mid+1;
			}
		}
		return -1;
	} 
    
    
    
    //2560012
    int findpar(vector<int>& nums) {
    	if(nums[0]<nums[nums.size()-1]){
    		return 0;
		}
		else{
			int low=0,high=nums.size()-1;
			int mid=(low+high)/2;
			while(low<=high){
				if(mid==0||mid==nums.size()-1) return 0;
				if(nums[mid]>=nums[mid-1]&&nums[mid]>nums[mid+1]){
					return mid;
				}
				else if(nums[mid]<nums[nums.size()-1]){
					//zuo走 
					high=mid-1;
					mid=(low+high)/2;
				}
				else if(nums[mid]>nums[0]){
					//you走 
					low=mid+1;
					mid=(low+high)/2;
				}
				else{
					//右走
					low=mid+1;
					mid=(low+high)/2;
				}
			}
			return 0;
		}
	}
    
};


int main(){
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
//	v.push_back(6);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(1);
//	v.push_back(2);
	
	Solution s;
	cout<<s.findpar(v);
	//cout<<"233"; 
	return 0;
}

