#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool mark[1001]={0};//0为素数
vector <int> index;
vector <int> indexn;
vector <int> nn;
vector <int> indexa;
vector <int> an;

int main(){
	int a,n;
	cin>>n>>a;
	mark[1]=1;
	for(int i=2;i<1000;i++){
		if(!mark[i]){
			index.push_back(i);
			int b=2;
			while(b*i<1000){
				mark[b*i]=1;
				b++;
			}
		}
	}
	
	int i=0,t=a;
	//分解a 
	for(int i=0;i<index.size();i++){
		if(index[i]>a){
			break;
		} 
		if(t%index[i]==0){
			indexa.push_back(index[i]);
			an.push_back(0);
			while(t%index[i]==0){
				an[an.size()-1]++;
				t=t/index[i];
			}
		}
		if(t==1){
			break;
		}
	}
	int k=1000;
	//分解n!
	for(int i=0;i<indexa.size();i++){
		int t=indexa[i];
		int num=0;
		int p=1;
		while(n/pow(t,p)>0){
			num+=n/pow(t,p);
			p++;
		}
		k=min(k,num/an[i]);
	} 
	
	cout<<k;
	return 0;
}

