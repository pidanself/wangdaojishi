#include<iostream>
using namespace std;
int Tree[1001];
int findRoot(int i){
	if(Tree[i]==-1) return i;
	else{
		int t=findRoot(Tree[i]);
		Tree[i]=t;
		return t;
	}
}


int a,b;//��·
int n,m;//������ĿΪn����·��ĿΪm 

int main(){
	
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		//��ʼ�����鼯
		for(int i=0;i<1000;i++){
			Tree[i]=-1;
		} 
		
		//�����· 
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b) Tree[b]=a;
		}
		
		int ans=0;
		//ͳ�Ƹ�����Ŀ
		for(int i=1;i<=n;i++){
			if(Tree[i]==-1) ans++;
		} 
		cout<<(ans-1)<<endl;
	}

	return 0;
}

