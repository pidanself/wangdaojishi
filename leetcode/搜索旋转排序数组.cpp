#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.size()==0) return -1;
        int par=findpar(nums);
        //cout<<par;
        if(nums[par]==target){
        	return 0;
		}
		else if(par==0){
			int ans=binaryfind(nums,0,nums.size()-1,target);
			return ans;
		}
		else{
			if(nums[par]>=target&&nums[nums.size()-1]<=target){
				//右边二分搜索 
				int ans=binaryfind(nums,par+1,nums.size()-1,target);
				if(ans!=-1) ans=ans-par;
				return ans;
			}
			else if(nums[par-1]<=target&&nums[0]>=target){
				//左边二分搜索 
				int ans=binaryfind(nums,0,par-1,target);
				if(ans!=-1) ans=nums.size()-par+ans;
				return ans;
			} 
		}
		return -1;
    }
    
    
    int findpar(vector<int>& nums){
    	int low,high;
		low=0;
		high=nums.size()-1;
		if(nums[low]>=nums[high]) return 0;
		int mid;
		while(true){
			mid=(low+high)/2;
			if(mid==0) return 1;
			if(mid==nums.size()-1) return nums.size()-1;
			if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
				return mid;
			}
			else if(nums[mid]>nums[nums.size()-1]&&nums[mid]>nums[0]){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		} 
	}
	
	int binaryfind(vector<int>& nums,int l,int h,int target){
		int low=l,high=h;
    	int mid=(low+high)/2;
    	while(low<=high){
    		if(nums[mid]==target){
    			return mid;
			}
			else if(nums[mid]>target){
				low=mid+1;
				mid=(low+high)/2;
			}
			else{
				high=mid-1;
				mid=(low+high)/2;
			}
		}		
    	return -1;
	}
};

int main(){

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		//初始化集合
		if(i!=0) cout<<endl;
		vector<int> v;
		int t;
		while(cin>>t){
			
			v.push_back(t);
			if(cin.get()=='\n')
				break;
		}
		while(cin>>t){
			
			Solution s;
			cout<<s.search(v,t);
			if(cin.get()=='\n')
				break;
			cout<<endl;
		}
	} 
	
}

