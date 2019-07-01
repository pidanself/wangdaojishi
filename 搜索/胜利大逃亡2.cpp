#include<iostream>
#include<queue>
using namespace std;
bool mark[51][51][51];

struct state{
	int x=0,y=0,z=0;
	int t=0;
};

int maze[51][51][51];

queue<state> q;

int go[][3]={
	0,0,1,
	0,0,-1,
	0,1,0,
	0,-1,0,
	1,0,0,
	-1,0,0
};

int main(){
	int a,b,c,T;
	cin>>a>>b>>c>>T;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			for(int k=0;k<c;k++){
				scanf("%d",&maze[i][j][k]);
				mark[i][j][k]=0;
			}
		}
	}
	
	state start;
	q.push(start);
	
	while(!q.empty()){
		state t=q.front();
		q.pop();
		if(t.x==a-1&&t.y==b-1&&t.z==c-1){
			cout<<t.t;
		}
		for(int i=0;i<6;i++){
			int nx,ny,nz;
			nx=t.x+go[i][0];
			ny=t.y+go[i][1];
			nz=t.z+go[i][2];
			if(nx>=0&&nx<a&&ny>=0&&ny<b&&nz>=0&&nz<c&&maze[nx][ny][nz]==0){
				if(mark[nx][ny][nz]==0&&(t.t<T)){
					mark[nx][ny][nz]=1;
					state tt;
					tt.x=nx;
					tt.y=ny;
					tt.z=nz;
					tt.t=t.t+1;
					q.push(tt);
				}
			}
		}
	}
	return 0;
}

