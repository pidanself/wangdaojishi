//我记住算了先。。。。日 

#include<iostream>
using namespace std;

void quickSort(int a[],int low,int high){
	if(low>=high) return;
	int key=a[low];
	int i=low,j=high+1;
	while(true){
		//从左到右 
		while(a[++i]<key){
			if(i==high){
				break;
			}
		}
		//从右到左
		while(a[--j]>key){
			if(j==low){
				break;
			}
		} 
		if(i>=j) break;
		//交换i,j对应的值
		int tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
		 
	}
	
	//交换中枢
	int tmp=a[j];
	a[j]=a[low];
	a[low]=tmp;
	quickSort(a,low,j-1);
	quickSort(a,j+1,high);
}

//挖坑法 失败 
void qSort(int a[],int low,int high){
	if(low>=high) return;
	int key=a[low];
	int index=low;
	int left=low,right=high+1;
	while(left<right){
		while(a[--right]>key){
			if(right==low) break;
		}
		a[index]=a[right];
		index=right;
		if(right==low) break;
		
		while(a[++left]<key){
			if(left==high) break;
		}
		a[index]=a[left];
		index=left;	
	}
	
	if(left==right){
		qSort(a,low,left-1);
		qSort(a,left+1,high);
	}
	
}


 
int main(){
	int nums[]={1,3,2,19,23,15,22,8};
	qSort(nums,0,sizeof(nums)/sizeof(int)-1);
	for(int i=0;i<=sizeof(nums)/sizeof(int)-1;i++){
		cout<<nums[i]<<endl;
	}
	return 0;
}

