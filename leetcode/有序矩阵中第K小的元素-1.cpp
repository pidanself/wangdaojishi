#include<iostream>
#include<queue>
using namespace std;

struct s{
	int i,j;
	int val;
	bool operator < (const s &b) const{
		return val>b.val;
	}
	s(int a=0,int b=0,int v=0){
		i=a;
		j=b;
		val=v;
	}
}; 

priority_queue<s> que;


class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        //初始化
		for(int p=0;p<matrix.size();p++){
			s t(p,0,matrix[p][0]);
			que.push(t);
		}
		int ans;
		for(int z=0;z<k;z++){
			s t= que.top();
			ans=t.val;
			que.pop();
			if(t.j+1<matrix[t.i].size()){
				s tt(t.i,t.j+1,matrix[t.i][t.j+1]);
				que.push(tt);
			}
			
		}
		return ans;
    }
};

int main(){
	vector<vector<int> > m(1);
	m[0].push_back(2000000000);
//	m[0].push_back(5);
//	m[0].push_back(9);
//	m[1].push_back(10);
//	m[1].push_back(11);
//	m[1].push_back(13);
//	m[2].push_back(12);
//	m[2].push_back(13);
//	m[2].push_back(15);
	Solution ss;
	cout<<ss.kthSmallest(m,8);

//测试得我的构建小根堆是没有什么问题的 
//	s a(0,0,2);
//	s b(0,1,3);
//	s c(1,1,10);
//	s d(1,2,-1);
//	que.push(a);
//	que.push(b);
//	que.push(c);
//	que.push(d);
//	cout<<que.top().val<<endl;
//	que.pop();
//	cout<<que.top().val<<endl;
//	que.pop();
//	cout<<que.top().val<<endl;
//	que.pop();
//	cout<<que.top().val<<endl;
}

