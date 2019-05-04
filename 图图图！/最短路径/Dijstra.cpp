#include<iostream>
#include<vector>
using namespace std;

struct E{
	int next;
	int cost;
};

vector<E> edge[101];

int mark[101];//1Ϊ��i�������ҵ����·��
int dis[101];//���·�� 

int main(){
	int n,m;
	cin>>n>>m;
	//�����,n���㣬m����
	for(int i=1;i<=n;i++){
		edge[i].clear();
	} 
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		E tmp;
		tmp.cost=c;
		tmp.next=b;
		edge[a].push_back(tmp);
		tmp.next=a;
		edge[b].push_back(tmp);
	}
	//��ʼ�� 
	for(int i=1;i<=n;i++){
		mark[i]=0;
		dis[i]=-1;
	}
	int newp=1;
	mark[1]=1;
	dis[1]=0;
	
	for(int i=0;i<n-1;i++){//����n-1��
		//��newp���ӵ����еı߽��б����ж�
		for(int j=0;j<edge[newp].size();j++){
			int t=edge[newp][j].next;
			int c=edge[newp][j].cost;
			if(mark[t]==1) continue;
			else{
				if(dis[t]==-1||dis[t]>c+dis[newp]){
					dis[t]=c+dis[newp];
				}
			}	
		}
		int min=11111111111;
		for(int j=1;j<=n;j++){
			if(mark[j]==1) continue;
			if(dis[j]==-1) continue;
			if(dis[j]<min){
				min=dis[j];
				newp=j;
			}
		}
	 	mark[newp]=1;
	}
	cout<<dis[n];
	return 0;
}

