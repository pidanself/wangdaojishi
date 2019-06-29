#include<iostream>
#include<algorithm>
using namespace std;
struct date{
	int xu;
	int num;
};

bool cmp(date a,date b){
	return a.num>b.num;
}

int main(){
	int m;
	cin>>m;
	date d[m];
	for(int i=0;i<m;i++){
		cin>>d[i].num;
		d[i].xu=i;
	}
	sort(d,d+m,cmp);
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=m-1;j>i;j--){
			if(d[i].num>2*d[j].num){
				if(d[i].xu<d[j].xu){
					ans++;
				}
			}
			else{
				break;
			}
		}
	}
	cout<<ans; 
	return 0;
}

