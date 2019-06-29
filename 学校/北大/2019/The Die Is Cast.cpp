#include<iostream>
#include<queue>
using namespace std;
//×îÐ¡¸ù¶Ñ 
priority_queue<int,vector<int>,greater<int> > q;
char ju[51][51];
int ans;
int w,h;
int t=0;

int dir[4][2]={
	-1,0,
	0,1,
	1,0,
	0,-1
};

void deepp(int i,int j){
	if(ju[i][j]=='X'){
		ju[i][j]='*';
		for(int k=0;k<4;k++){
			int ii,jj;
			ii=i+dir[k][0];
			jj=j+dir[k][1];
			if(ii>=0&&ii<h&&jj>=0&&jj<w){
				deepp(ii,jj);
			}
		}
	}
	else{
		return;
	}
}

void deep(int i,int j){
	if(ju[i][j]=='.'){
		return ;
	}
	else if(ju[i][j]=='*'){
		ju[i][j]='.';
		for(int k=0;k<4;k++){
			int ii,jj;
			ii=i+dir[k][0];
			jj=j+dir[k][1];
			if(ii>=0&&ii<h&&jj>=0&&jj<w){
				deep(ii,jj);
			}
		}
	}
	else if(ju[i][j]=='X'){
		t++;
		ju[i][j]='*';
		for(int k=0;k<4;k++){
			int ii,jj;
			ii=i+dir[k][0];
			jj=j+dir[k][1];
			if(ii>=0&&ii<h&&jj>=0&&jj<w){
				deepp(ii,jj);
			}
		}
		ju[i][j]='.';
		for(int k=0;k<4;k++){
			int ii,jj;
			ii=i+dir[k][0];
			jj=j+dir[k][1];
			if(ii>=0&&ii<h&&jj>=0&&jj<w){
				deep(ii,jj);
			}
		}
	}
}


int main(){

	
	int nums=1;
	while(scanf("%d %d",&w,&h)!=EOF&&w!=0&&h!=0){
		ans=0;
		//initial
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>ju[i][j];
			}
		}
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(ju[i][j]=='*'||ju[i][j]=='X'){
					deep(i,j);
					q.push(t);
					t=0;
				}
			}
		}
		cout<<"Throw "<<nums<<endl;
		nums++;
		while(!q.empty()){
			int tt=q.top();
			q.pop();
			if(!q.empty()){
				cout<<tt<<" ";
			}
			else{
				cout<<tt<<endl;
			}
		}
		cout<<endl;
	}
	
	return 0;
}

