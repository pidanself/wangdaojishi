#include<iostream>
#include<vector> 
#include<queue>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        bool ans=false;
        vector<vector<int> > graph(numCourses);
        //入度为零的点的集合
		queue<int> pointZero;
		//各个点的入度
		int ru[numCourses]={0};
		 
        //预处理
		for(int i=0;i<prerequisites.size();i++){
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
			ru[prerequisites[i][0]]++;
		} 
		for(int i=0;i<numCourses;i++){
			if(ru[i]==0){
				pointZero.push(i);
			}
		}
		
		int nums=0;//处理掉的点的个数 
		while(!pointZero.empty()){
			int t=pointZero.front();
			pointZero.pop();
			for(int i=0;i<graph[t].size();i++){
				int tt=graph[t][i];
				ru[tt]--;
				if(ru[tt]==0){
					pointZero.push(tt);
				} 
			}
			nums++;
		}
		
		if(nums!=numCourses){
			return false;
		}
		else{
			return true;
		}
    }
};

int main(){





	return 0;
}

