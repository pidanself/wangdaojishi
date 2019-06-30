#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int> >& times, int N, int K) {
    	int edge[101][101];
    	memset(edge,-1,sizeof(edge));
    	for(int i=0;i<101;i++){
    		edge[i][i]=0;
		}
		for(int i=0;i<times.size();i++){
			edge[times[i][0]][times[i][1]]=times[i][2];
		}
        for(int k=1;k<=N;k++){
        	for(int i=0;i<=N;i++){
        		for(int j=0;j<=N;j++){
        			if(edge[i][k]==-1||edge[k][j]==-1) continue;
        			else if(edge[i][j]==-1||(edge[i][k]+edge[k][j]<edge[i][j])){
        				edge[i][j]=edge[i][k]+edge[k][j];
					}
				}
			}
		}
		
		int ans=0;
		for(int i=1;i<=N;i++){
			if(edge[K][i]==-1) return -1;
			else{
				ans=max(edge[K][i],ans);
			}
		}
		return ans;
    }
};


int main(){
	

	return 0;
}

