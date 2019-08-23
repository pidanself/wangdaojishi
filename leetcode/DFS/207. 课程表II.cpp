#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        //�� 
        vector<int> ans;vector<int> ansB;
        int inD[numCourses]={0};//��¼��ȵ�����
		vector<vector<int> > edge(numCourses);//��¼�ߣ�i��ָ������е�
		queue<int> qPoint;//���Ϊ0�����е� 
		
		//Ԥ����
		for(int i=0;i<prerequisites.size();i++){
			int inP,outP;
			inP=prerequisites[i][0];
			outP=prerequisites[i][1];
			inD[inP]++;
			edge[outP].push_back(inP);
		} 
		//���Ϊ0�ĵ������
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

