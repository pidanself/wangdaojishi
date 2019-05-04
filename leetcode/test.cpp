#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
vector<vector<int> > vv(16);
class Solution {
public:
    
//    int n;
//    int d[16]={0};
	
//    int dfs(int h){
//    	int ans=0;
//    	if(h>n){
//    		return 1;
//		}
//		for(int i=0;i<v[h].size();i++){
//			int t;
//			t=v[h][i];
//			if(d[t]!=0){
//				d[t]=h;
//				ans+=dfs(h+1);
//				d[t]=0;
//			}
//		}
//		return ans;
//	} 
    
    
//	int countArrangement(int N) {
//    	n=N;
//    	//Ô¤´¦Àí 
//        for(int i=1;i<=N;i++){
//        	
//        	for(int j=1;j<=i;j++){
//        		if(i%j==0){
//        			v[i].push_back(j);
//				}
//			}
//			for(int j=i+1;j<=N;j++){
//				if(j%i==0){
//					v[i].push_back(j);
//			}
//		}
//		int ans=dfs(1);
//		return ans;
//    }
//	}
    
};

int main(){
	vector<vector<int> > v(3);
	v[1].push_back(1);
	cout<<v[1][0];

	return 0;
}

