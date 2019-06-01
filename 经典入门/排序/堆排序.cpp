#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

void adjust(int arr[],int i,int len){
	int tmp=arr[i];
	
	for(int k=2*i+1;k<len;k=2*k+1){
		if(k+1<len&&arr[k]<arr[k+1]){
			k++;
		}
		
		if(arr[k]>tmp){
			swap(arr,k,i);
			i=k;
		}
		else{
			break;
		}
	}
	
}

void heapSort(int arr[],int low,int high){
	int len=high-low+1;
	//¶ÑµÄ³õÊ¼»¯ 
	for(int i=len/2-1;i>=0;i--){
		adjust(arr,i,len);
	}
	
	for(int i=len-1;i>=0;i--){
		
		swap(arr,i,0);
		
		adjust(arr,0,i);
		
	}
}

int main(){
	int nums[]={1,3,2,19,23,15,22,8};
	heapSort(nums,0,sizeof(nums)/sizeof(int)-1);
	for(int i=0;i<=sizeof(nums)/sizeof(int)-1;i++){
		cout<<nums[i]<<endl;
	}
	return 0;
}

