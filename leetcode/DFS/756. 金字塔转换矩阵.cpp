#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
		for(int i=0;i<allowed.size();i++){
			string temp=allowed[i];
			if(m.count(temp.substr(0,2))==1){
				string temp1=m[temp.substr(0,2)];
				if(temp1.find(temp.substr(2,1))==temp1.npos){
					string temp2=m[temp.substr(0,2)]+temp.substr(2,1);
					m[temp.substr(0,2)]=temp2;
				} 
			}
			else{
				m.insert(make_pair(temp.substr(0,2),temp.substr(2,1)));
			}
		}
//		map<string,string>::iterator it;
//		
//		for(it=m.begin();it!=m.end();it++){
//			cout<<it->first<<","<<it->second<<endl;
//		}
		
		return dfs(bottom);
    }
    
private:
	//使用allowed构造map
	map<string,string> m;
	bool dfs(string bottom){
		bool ans=false;
		vector<string> v=buildV(bottom);
//		cout<<v.size()<<endl;
//		for(int i=0;i<v.size();i++){
//			cout<<v[i]<<endl;
//		}
		if(bottom.size()==2){
			if(v.empty()){
				return false;
			}
			else{
				return true;
			}
		}
		else{
			if(v.empty()){
				//无法向上构造 
				return false; 
			}
			else{
				for(int i=0;i<v.size();i++){
					string temp=v[i];
					ans=ans||dfs(temp);
				}
			}
			return ans;
		}
	}
	
	vector<string> buildV(string bottom){
		vector<string> ans;
		string anst;
		for(int i=0;i+1<bottom.size();i++){
			if(m.count(bottom.substr(i,2))==1){
				if(m[bottom.substr(i,2)].size()==1){
					anst.append(m[bottom.substr(i,2)]);
					continue;
				}
				else{
					for(int j=0;j<m[bottom.substr(i,2)].size();j++){
						string t=anst;
						t.append(m[bottom.substr(i,2)].substr(j,1));
						if(i+1==bottom.size()-1){
							ans.push_back(t);
						}
						else{
							vector<string> tvector=buildV(bottom.substr(i+1));
							if(tvector.empty()){
								return ans;
							}
							else{
								for(int jj=0;jj<tvector.size();jj++){
									string tt=t;
									tt.append(tvector[jj]);
									ans.push_back(tt);
								}
							}
						}
					}
					return ans;
				}
			}
			else{
				return ans;
			}
		}
		ans.push_back(anst);
		return ans;
	}
};


int main(){
	string bottom="CBDDA";
    vector<string> allowed;
    allowed.push_back("ACC");
    allowed.push_back("ACA");
    allowed.push_back("AAB");
    allowed.push_back("BCA");
    allowed.push_back("BCB");
    allowed.push_back("BAC");
    allowed.push_back("BAA");
    allowed.push_back("CAC");
    allowed.push_back("BDA");
    allowed.push_back("CAA");
    allowed.push_back("CCA");
    allowed.push_back("CCC");
    allowed.push_back("CCB");
    allowed.push_back("DAD");
    allowed.push_back("CCD");
    allowed.push_back("DAB");
    allowed.push_back("ACD");
    allowed.push_back("DCA");
    allowed.push_back("CAD");
    allowed.push_back("CBB");
    allowed.push_back("ABB");
    allowed.push_back("ABC");
    allowed.push_back("ABD");
    allowed.push_back("BDB");
    allowed.push_back("BBC");
    allowed.push_back("BBA");
    allowed.push_back("DDA");
    allowed.push_back("CDD");
    allowed.push_back("CBC");
    allowed.push_back("CBA");
    allowed.push_back("CDA");
    allowed.push_back("DBA");
    allowed.push_back("ABA");
    Solution s;
    cout<<s.pyramidTransition(bottom,allowed);
	return 0;
}

