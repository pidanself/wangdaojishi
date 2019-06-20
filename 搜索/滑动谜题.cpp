#include<iostream>
#include<set>
#include<queue>
#include<sstream>
using namespace std;
string i2s(int x){
	stringstream sstr;
	string str;
	sstr<<x;
	sstr>>str;
	return str;
}



struct state{
	string s;
	int x,y;
	int t=0;
};

queue<state> Q;
//相当于标记 
set<string> S;

int go[][2]={
	0,1,
	1,0,
	-1,0,
	0,-1
};

class Solution {
public:
    int slidingPuzzle(vector<vector<int> >& board) {
    	string head;
    	string target="123450";
    	int a,b;
        for(int i=0;i<board.size();i++){
        	for(int j=0;j<board[i].size();j++){
        		head+=i2s(board[i][j]);
        		if(board[i][j]==0){
        			a=i;
					b=j;
				}
			} 
		}
		S.insert(head);
		state tem;
		tem.s=head;
		tem.t=0;
		tem.x=a;
		tem.y=b;
		Q.push(tem);
		
		while(Q.empty()==false){
			state pi=Q.front();
			Q.pop();
			if(target==pi.s){
				return pi.t;
			}
			for(int i=0;i<4;i++){
				int xx,yy;
				xx=go[i][0]+pi.x;
				yy=go[i][1]+pi.y;
				if(xx>=0&&xx<=1&&yy>=0&&yy<=2){
					state newt;
					newt.t=pi.t+1;
					newt.x=xx;
					newt.y==yy;
					newt.s=pi.s;
					int aa,bb;
					aa=pi.x*3+pi.y;
					bb=xx*3+yy;
					newt.s[aa]=pi.s[bb];
					newt.s[bb]=pi.s[aa];
					
					if(S.count(newt.s)==0){
						S.insert(newt.s);
						Q.push(newt);
					}
				}
			}
		}
		return -1;
    }
};




int main(){
	vector<vector<int> > v(2);
	v[0].push_back(1);
	v[0].push_back(2);
	v[0].push_back(3);
	v[1].push_back(0);
	v[1].push_back(4);
	v[1].push_back(5);
	Solution s;
	cout<<s.slidingPuzzle(v);
	return 0; 
}

