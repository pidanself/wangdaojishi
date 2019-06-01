#include<iostream>
#include<vector> 
using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans(numRows);
       
		for(int i=0;i<numRows;i++){
			vector<int> t;
        	for(int j=0;j<=i;j++){
        		if(j==0||j==i){
        			t.push_back(1);
        			//ans[i].push_back(1);
				}
				else{
					t.push_back(ans[i-1][j-1]+ans[i-1][j]);
					//ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
				}
				
			}
			ans.push_back(t);
		}
		
		for(int i=0;i<5;i++){
		for(int j=0;j<=i;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
		
		return ans;
    }
};

int main(){
	Solution s;
	s.generate(5);
	
}

