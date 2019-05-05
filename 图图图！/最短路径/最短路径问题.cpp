#include<iostream>
#include<vector> 
using namespace std;
struct E{
	int next;
	int d;
	int p;
};
vector<E> edge[101];

bool mark[101];
int dis[101];//路径长度 
int cost[101];//花费
 
int main(){
	
	int n,m;
	cin>>n>>m;
	//初始化
	for(int i=1;i<=n;i++){
		mark[i]=false;
		dis[i]=-1;
		cost[i]=-1;
	} 
	
	//输入m条边
	for(int i=0;i<m;i++){
		int a,b,d,p;
		cin>>a>>b>>d>>p;
		E tmp;
		tmp.d=d;
		tmp.p=p;
		tmp.next=b;
		edge[a].push_back(tmp);
		tmp.next=a;
		edge[b].push_back(tmp);
	} 
	
	int s,t,newp;
	cin>>s>>t;
	mark[s]=true;
	dis[s]=0;
	cost[s]=0;
	newp=s;
	//进行n-1次循环 
	for(int k=0;k<n-1;k++){
		
		//对newp点连接的所有边进行试探
		for(int i=0;i<edge[newp].size();i++){
			int tnext=edge[newp][i].next;
			int td=edge[newp][i].d;
			int tp=edge[newp][i].p;
			if(mark[tnext]) continue;
			
			if(dis[tnext]==-1||(dis[tnext]>dis[newp]+td)||
			((dis[tnext]==dis[newp]+td)&&cost[tnext]>cost[newp]+tp)
			){
				dis[tnext]=dis[newp]+td;
				cost[tnext]=cost[newp]+tp;
			}
		} 
		int min=222222;
		for(int i=1;i<=n;i++){
			if(mark[i]) continue;
			if(dis[i]==-1) continue;
			if(dis[i]<min){
				min=dis[i];
				newp=i;
			}
		}
		mark[newp]=true;
	}
	
	cout<<dis[t]<<" "<<cost[t];
	
	return 0;
}

