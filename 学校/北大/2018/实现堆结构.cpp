#include<iostream>
#include<queue>
using namespace std;
int main(){
		int n;
		scanf("%d",&n);
		priority_queue<int,vector<int>,greater<int> > q;
		for(int j=0;j<n;j++){
			int type;
			scanf("%d",&type);
			if(type==1){
				int tt;
				scanf("%d",&tt);
				q.push(tt);
			}
			else if(type==2){
				if(q.empty()){
					continue;
				}
				else{
				
						printf("%d\n",q.top());
					
					q.pop();
				}
			}
		}
	
	return 0;
}

