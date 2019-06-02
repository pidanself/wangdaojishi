#include<iostream>
#include<vector>
#include<queue> 
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int> >& p) {
        queue<int> Q;
        int inD[501]={0}; 
        vector<int> Edge[501];
        for(int i=0;i<p.size();i++){
        	int a=p[i][0],b=p[i][1];
        	inD[b]++;
        	Edge[a].push_back(b);
		}
		for(int i=0;i<n;i++){
			if(inD[i]==0){
				Q.push(i);
			}
		}
		int cnt=0;
		while(Q.empty()==false){
            cnt++;
			int t=Q.front();
			Q.pop();
            for(int i=0;i<Edge[t].size();i++){
            	if(--inD[Edge[t][i]]==0){
					Q.push(Edge[t][i]);
				}	
        	}
		}
		if(cnt==n){
			return true;
		}
		else{
			return false;
		}
    }
};


int main(){

	vector<vector<int> > t(1);
	t[0].push_back(1);
	t[0].push_back(0);
	Solution s;
	
	cout<<s.canFinish(2,t);
	return 0;
}

