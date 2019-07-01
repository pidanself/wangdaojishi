#include<iostream>
#include<queue>
using namespace std;
//״̬ 
struct state{
	int s,m,n,t;
	state(int a=0,int b=0,int c=0,int d=0){
		s=a;
		m=b;
		n=c;
		t=d;
	}
};
//����
queue<state> Q;
//���
bool mark[101][101][101]; 
 

bool success(int a,int b,int c){
	if(a==0&&(b==c)) return true;
	if(b==0&&(a==c)) return true;
	if(c==0&&(a==b)) return true;
	
	return false;
}

void dao(int &a,int &b,int B){
	int res=B-b;
	if(res>=a){
		//ȫ��
		b=b+a;
		a=0; 
	}
	else{
		//��B����
		b=B;
		a=a-res; 
	}
}

void pan(int S,int M,int N){
	//���г�ʼ��
	while(Q.empty()==false){
		Q.pop();
	} 
	for(int i=0;i<S;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				mark[i][j][k]=false;
			}
		}
	}
	
	state head(S,0,0,0);
	Q.push(head);
	while(Q.empty()==false){
		state t=Q.front();
		Q.pop();
		if(success(t.s,t.m,t.n)){
			cout<<t.t<<endl;
			return;
		}
		//����6����չ
		int ss,mm,nn;
		ss=t.s;
		mm=t.m;
		nn=t.n;
		dao(ss,mm,M);
		if(mark[ss][mm][nn]==false){
			mark[ss][mm][nn]=true;
			state temp;
			temp.s=ss;
			temp.m=mm;
			temp.n=nn;
			temp.t=t.t+1;
			Q.push(temp);
		}	
		
		//�ָ�
		ss=t.s;
		mm=t.m;
		nn=t.n;
		dao(mm,ss,S);
		if(mark[ss][mm][nn]==false){
			mark[ss][mm][nn]=true;
			state temp;
			temp.s=ss;
			temp.m=mm;
			temp.n=nn;
			temp.t=t.t+1;
			Q.push(temp);
		}	
		
		//�ָ�
		ss=t.s;
		mm=t.m;
		nn=t.n;
		dao(ss,nn,N);
		if(mark[ss][mm][nn]==false){
			mark[ss][mm][nn]=true;
			state temp;
			temp.s=ss;
			temp.m=mm;
			temp.n=nn;
			temp.t=t.t+1;
			Q.push(temp);
		}	
		
		//�ָ�
		ss=t.s;
		mm=t.m;
		nn=t.n;
		dao(nn,ss,S);
		if(mark[ss][mm][nn]==false){
			mark[ss][mm][nn]=true;
			state temp;
			temp.s=ss;
			temp.m=mm;
			temp.n=nn;
			temp.t=t.t+1;
			Q.push(temp);
		}	
		
		//�ָ�
		ss=t.s;
		mm=t.m;
		nn=t.n;
		dao(mm,nn,N);
		if(mark[ss][mm][nn]==false){
			mark[ss][mm][nn]=true;
			state temp;
			temp.s=ss;
			temp.m=mm;
			temp.n=nn;
			temp.t=t.t+1;
			Q.push(temp);
		}	
		
		//�ָ�
		ss=t.s;
		mm=t.m;
		nn=t.n;
		dao(nn,mm,M);
		if(mark[ss][mm][nn]==false){
			mark[ss][mm][nn]=true;
			state temp;
			temp.s=ss;
			temp.m=mm;
			temp.n=nn;
			temp.t=t.t+1;
			Q.push(temp);
		}	
	}
	cout<<"NO"<<endl;
}

int main(){
	//ƿ�Ӵ�С������ 
	int S,M,N;	
	while(scanf("%d %d %d",&S,&M,&N)!=EOF&&S!=0){
		pan(S,M,N);
	}
	return 0;
}

