#include<iostream>
#include<queue>
using namespace std;
//地图
int maze[51][51][51];
//标记 
bool mark[51][51][51]; 
//状态
struct N{
	int x=0,y=0,z=0;
	int t=0;
}; 
//队列
queue<N> q;
//go!
int go[][3]={
	1,0,0,
	0,1,0,
	-1,0,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};

int main(){
	int num;
	cin>>num; 
	while(num--!=0){
		int A,B,C,T;
		cin>>A>>B>>C>>T;
		for(int h=0;h<A;h++){
			for(int i=0;i<B;i++){
				for(int j=0;j<C;j++){
					cin>>maze[i][j][h];
					mark[i][j][h]=0;
				}
			}
		}
		while(q.empty()==false){
			q.pop();
		}
		N start;
		q.push(start);
		while(q.empty()==false){
			N t=q.front();
			q.pop();
			if(t.x==B-1&&t.y==C-1&&t.z==A-1) {
				cout<<t.t<<endl;
				cout<<"success!"<<endl;
				goto success;
			}
			for(int i=0;i<6;i++){
				int tx,ty,tz,tt;
				tx=go[i][0]+t.x;
				ty=go[i][1]+t.y;
				tz=go[i][2]+t.z;
				tt=1+t.t;
				if(tt>T) break;
				if(tx<0||tx>=B||ty<0||ty>=C||tz<0||tz>=A) continue;
				if(!mark[tx][ty][tz]&&maze[tx][ty][tz]==0){
					mark[tx][ty][tz]=true;
					N r;
					r.x=tx;
					r.y=ty;
					r.z=tz;
					r.t=tt;
					q.push(r);
				}
			}
		}
		cout<<"fail"<<endl;
	success:
		int i;
	}
	
	return 0;
}

