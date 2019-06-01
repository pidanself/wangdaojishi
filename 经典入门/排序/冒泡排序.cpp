#include<iostream>
using namespace std;

//从小到大 
void bubbleSort(int nums[],int low,int high){
	for(int i=low;i<high;i++){
		int mark=1;	
		for(int j=0;j<high-i;j++){
			if(nums[j]>nums[j+1]){
				int t=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=t;
				mark=0;
			}	
		}
		if(mark==1) break;	
	}
	
} 

//从大到小，把小的往后放就行 

int main(){
	int nums[]={1,3,2,19,23,15,22,8};
	bubbleSort(nums,0,sizeof(nums)/sizeof(int)-1);
	for(int i=0;i<=sizeof(nums)/sizeof(int)-1;i++){
		cout<<nums[i]<<endl;
	}

	return 0;
}

