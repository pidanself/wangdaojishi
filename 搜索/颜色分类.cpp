#include<iostream>
using namespace std;
//Ë«Ö¸ÕëÎÊÌâ

 
int main(){
	int nums[]={2,0,2,1,1,0};
	int l=0,r=5,n=0;
	while(n<r){
		if(nums[n]==2){
			int t=nums[r];
			nums[r]=nums[n];
			nums[n]=t;
			r--;
		}
		else if(nums[n]==1){
			n++;
		}
		else{
			int t=nums[l];
			nums[l]=nums[n];
			nums[n]=t;
			l++;
			n++;
		}
	}
	for(int i=0;i<6;i++){
		cout<<nums[i]<<endl;
	}
	return 0;
}

