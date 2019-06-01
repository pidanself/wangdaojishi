#include<iostream>
using namespace std;


void min_heapify(int arr[],int start,int end){
	int dad=start;
	int son=dad*2+1;
	while(son<=end){
		if(son+1<=end&&arr[son+1]<arr[son]){
			son++;
		}
		if(arr[son]<arr[dad]){
			swap(arr[son],arr[dad]);
			dad=son;
			son=2*dad+1;
		}
		else return;
	}
	
}




void heap_sort(int arr[],int len){
	for(int i=len/2-1;i>=0;i--){
		min_heapify(arr,i,len-1);
	}
	
	for(int i=len-1;i>0;i--){
		swap(arr[i],arr[0]);
		min_heapify(arr,0,i-1);
	}
}

int main(){
	int arr[]={3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 29, 7, 3, 11, 2, 5, 9, 17, 4, 10, 2, 6 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	heap_sort(arr, len);
	for (int i = 0; i < len; i++)
	    cout << arr[i] << ' ';
    cout << endl;
    return 0;

}

