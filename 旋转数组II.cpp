#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        if(nums.size()==1){
    		if(target==nums[0]) return true;
    		else return false;
		}
        int ans;
        int p=findpar(nums);
        if(p==-1||p==nums.size()-1){
        	ans=binaryfind(nums,0,nums.size()-1,target);
		}
		else{
			if(nums[p]>=target&&nums[0]<=target){
				ans=binaryfind(nums,0,p,target);
			}
			else if(nums[p+1]<=target&&nums[nums.size()-1]>=target){
				ans=binaryfind(nums,p+1,nums.size()-1,target);
			}
            else{
                ans=-1;
            }
		}
        if(ans==-1) return false;
        else return true;
    }
    
    
    int binaryfind(vector<int>& nums,int low,int high,int target){
    	int l,h;
    	l=low,h=high;
    	int mid;
    	while(l<=h){
    		mid=(l+h)/2;
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
    		return -1;
		}
		else{
			int low=0,high=nums.size()-1;
			int mid=(low+high)/2;
			while(low<=high){
				if(mid==nums.size()-1) return 0;
				if(mid==0&&nums[mid]>nums[1]) return 1;
				if(mid==0) return 0;
				if(nums[mid]>=nums[mid-1]&&nums[mid]>nums[mid+1]){
					return mid;
				}
				else if(nums[mid]<=nums[nums.size()-1]&&nums[mid]>=nums[mid+1]){
					//zuo走 
					high=mid-1;
					mid=(low+high)/2;
				}
				else if(nums[mid]>=nums[0]&&nums[mid]<=nums[mid-1]){
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
	
	v.push_back(3);
	v.push_back(1);
//	v.push_back(6);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(1);
//	v.push_back(2);
	
	Solution s;
	cout<<s.search(v,1);
	//cout<<"233"; 
	return 0;
}
