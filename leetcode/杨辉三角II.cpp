#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i=0;i<=rowIndex;i++){
        	for(int j=i;j>=0;j--){
        		if(j==i){
        			ans.push_back(1);
				}
				else if(j==0){
					continue;
				}
				else{
					ans[j]=ans[j-1]+ans[j];
				}
			}
		}
		return ans;
    }
};


int main(){
	


}

