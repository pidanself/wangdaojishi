//把一层当作一个整体仍是有问题 
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x):val(x),left(NULL),right(NULL){
	 
	 }
 };
vector<int> *cal(TreeNode *root){
	vector<int> *a=new vector<int>;
	
	vector<TreeNode *> t,tt;
	t.push_back(root);
	while(t.size()!=0||tt.size()!=0){
		if(t.size()!=0){
			int tmp=0;
			for(int i=0;i<t.size();i++){
				tmp+=t[i]->val;
				if(t[i]->left!=NULL) tt.push_back(t[i]->left);
				if(t[i]->right!=NULL) tt.push_back(t[i]->right);
			}
			(*a).push_back(tmp);
			t.clear();
		}
		else{
			int tmp=0;
			for(int i=0;i<tt.size();i++){
				tmp+=tt[i]->val;
				if(tt[i]->left!=NULL) t.push_back(tt[i]->left);
				if(tt[i]->right!=NULL) t.push_back(tt[i]->right);
			}
			(*a).push_back(tmp);
			tt.clear();
		}
		
	}
	
	return a;
} 

int dfs(vector<int> *a,int i,bool is){
	if(i>=(*a).size()){
		return 0;
	}
	if(is){

		return (*a)[i]+max(dfs(a,i+2,true),dfs(a,i+2,false));
	}
	else{
		
		return max(dfs(a,i+1,true),dfs(a,i+1,false));
	}
}

int main(){
	TreeNode *root=new TreeNode(4);
	root->left=new TreeNode(1);


	root->left->left=new TreeNode(2);
	root->left->left->left=new TreeNode(3);
	
	
	vector<int> *a;
	a=cal(root);
	
	int ans=dfs(a,0,true);
	int anss=dfs(a,0,false);
	ans=max(ans,anss);
	cout<<ans;
	return 0;
}

