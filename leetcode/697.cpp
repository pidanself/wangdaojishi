#include<iostream>
#include<vector>
using namespace std;

struct st{
        int s=-1,e=-1;
        int count=-1;
    }store[500000];
    
    int findShortestSubArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(store[nums[i]].count==-1) {
                store[nums[i]].s=i;
                store[nums[i]].e=i;
                store[nums[i]].count++;
                store[nums[i]].count++;
            }
            else{
                store[nums[i]].e=i;
                store[nums[i]].count++;
            }
        }
        int maxx=0,minn=50000;
        for(int i=0;i<50000;i++){
            if(maxx<store[i].count){
                maxx=store[i].count;
                minn=store[i].e-store[i].s+1;
            }
            else if(maxx==store[i].count){
                int t=store[i].e-store[i].s+1;
                minn=min(minn,t);
            }
        }
        return minn;
    }

int main(){
	
	//int a[5]={1,2,2,3,1};
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);
	int i=findShortestSubArray(a);
	cout<<i;

	return 0;
}

