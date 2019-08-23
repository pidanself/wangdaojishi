#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        //答案 
        vector<int> ans;vector<int> ansB;
        int inD[numCourses]={0};//记录入度的数组
		vector<vector<int> > edge(numCourses);//记录边，i点指向的所有点
		queue<int> qPoint;//入度为0的所有点 
		
		//预处理
		for(int i=0;i<prerequisites.size();i++){
			int inP,outP;
			inP=prerequisites[i][0];
			outP=prerequisites[i][1];
			inD[inP]++;
			edge[outP].push_back(inP);
		} 
		//入度为0的点入队列
		for(int i=0;i<numCourses;i++){
			if(inD[i]==0){
				qPoint.push(i);
			}
		}
		
		int nums=0;
		
		while(!qPoint.empty()){
			int t=qPoint.front();
			ans.push_back(t);
			qPoint.pop();
			nums++;
			for(int i=0;i<edge[t].size();i++){
				int tt=edge[t][i];
				inD[tt]--;
				if(inD[tt]==0){
					qPoint.push(tt);
				}
			}
		}
		if(nums==numCourses){
			return ans;
		}
		else{
			return ansB;
		}
    }
};


int main(){
	int n=2;
	vector<vector<int> > prerequisites(1);
	prerequisites[0].push_back(1);
	prerequisites[0].push_back(0);
	Solution s;
	s.findOrder(n,prerequisites);
	return 0;
}

