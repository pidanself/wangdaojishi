#include<iostream>
#include<vector> 
#include<map>
using namespace std;

int main(){
	int num;
	cin>>num;
	string input[100];
	for(int i=0;i<num;i++){
		cin>>input[i];
	}
	cout<<"SHOULD BE:"<<endl;
	for(int i=0;i<num;i++){
		vector<string> ans;
		map<string,int> m;
		//cout<<endl;
		if(input[i].size()<=10){
			cout<<"[]"<<endl;
			continue;
		} 
		for(int j=0;j<=input[i].size()-10;j++){
			string substr=input[i].substr(j,10);
			if(m.find(substr)!=m.end()){
				if(m[substr]==1){
					ans.push_back(substr);
				}
				m[substr]++;
			}
			else{
				m[substr]=1;
			}
			
		}
		cout<<"[";
		if(ans.size()!=0){
			for(int j=0;j<ans.size()-1;j++){
				cout<<ans[j]<<",";
			}
			cout<<ans[ans.size()-1];
		}
		if(i==num-1){
			cout<<"]";
		}
		else{
			cout<<"]"<<endl;
		}
		
	}
	
	return 0;
}
 
