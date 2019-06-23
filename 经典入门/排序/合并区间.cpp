#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(vector<int> a,vector<int> b){
	return a[0]<b[0];
}

int main(){
	vector<vector<int> > vec(4);
	vec[0].push_back(1);
	vec[0].push_back(3);
	vec[1].push_back(2);
	vec[1].push_back(6);
	
	vec[2].push_back(15);
	vec[2].push_back(18);
	
	vec[3].push_back(8);
	vec[3].push_back(10);
	
	vector<vector<int> > ans;
	
	sort(vec.begin(),vec.end(),cmp);
	int i=0;
	while(i<vec.size()){
		int l=vec[i][0],r=vec[i][1];
		int j=i+1;
		while(j<vec.size()&&vec[j][0]<=r){
			r=max(r,vec[j][1]);
			j++;
		}
		//ans.push_back(vector<int>{l,r});
		vector<int> a;
		a.push_back(l);
		a.push_back(r);
		ans.push_back(a);
		if(j>=vec.size()){
			break;
		}
		i=j;
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][0]<<endl;
	}
	
	return 0;
}

