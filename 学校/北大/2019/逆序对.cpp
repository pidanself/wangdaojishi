#include<iostream>
#include<vector>
using namespace std;

class AntiOrder {
public:
	int ans;
    int count(vector<int> A, int n) {
        //利用归并排序顺便计算个数 
        if(n==0) return 0;
        ans=0;
        vector<int> B(n,0);
        mergeSort(A,B,0,n-1);
        return ans;
    }
    
    void mergeSort(vector<int> &A,vector<int> &B,int s,int e){
    	int mid;
    	if(s<e){
    		mid=s+(e-s)/2;
    		mergeSort(A,B,s,mid);
    		mergeSort(A,B,mid+1,e);
    		merge(A,B,s,mid,e);
		}
		return;
	}
	
	void merge(vector<int> &A,vector<int> &B,int s,int mid,int e){
		int i=s,j=mid+1,k=s;
		while(i!=mid+1&&j!=e+1){
			if(A[i]>A[j]){
				ans+=mid-i+1;
				B[k++]=A[j++];
			}
			else{
				B[k++]=A[i++];
			}
		}
		while(i!=mid+1){
			B[k++]=A[i++];
		}
		while(j!=e+1){
			B[k++]=A[j++];
		}
		for(i=s;i<=e;i++){
			A[i]=B[i];
		}
	}
};


int main(){
	AntiOrder a;
	vector<int> A;
	for(int i=1;i<=7;i++){
		A.push_back(i);
	}
	A.push_back(0);
	
	a.count(A,8);
	cout<<a.ans;
	

	return 0;
}

