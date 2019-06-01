#include<iostream>
using namespace std;


void min_heapify(int arr[],int start,int end){
	int dad=start;
	int son=2*dad+1;
	while(son<=end){
		if(son+1<=end&&arr[son+1]<arr[son]) son++;
		if(arr[son]<arr[dad]){
			swap(arr[son],arr[dad]);
			dad=son;
			son=2*dad+1;
		}
		else{
			return;
		}
	}
	
	
}

int k_min(int arr[],int len,int k){
	for(int i=len/2-1;i>=0;i--){
		min_heapify(arr,i,len-1);
	}
	int ans=arr[0];
	for(int i=1;i<k;i++){
		
		swap(arr[0],arr[len-i]);
		min_heapify(arr,0,len-i-1);
		ans=arr[0];
	}
	
	return ans;
}


int main(){
	int arr[]={3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 29, 7, 3, 11, 2, 5, 9, 17, 4, 10, 2, 6 };
	int len=sizeof(arr)/sizeof(int);
	int ans=k_min(arr,len,8);
	cout<<"µÚkĞ¡Îª£º"<<ans;
}

