#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        //二叉树转图
		buildMap(NULL,root);
		
		//对图进行宽度优先搜索（递归）
		dfs(NULL,target,K);
		
		//返回答案
		return ans; 
    }
    
    void dfs(TreeNode* parent , TreeNode* target , int k){
    	if(k==0){
    		ans.push_back(target->val);
    		return;
		}
		for(int i=0;i<m[target].size();i++){
			if(parent!=m[target][i]){
				dfs(target,m[target][i],k-1);
			}
		}
		return ;
	}
    
    void buildMap(TreeNode* parent,TreeNode* child){
    	if(!child) return;
    	if(parent){
    		//如果父节点存在加入m中
			m[parent].push_back(child);
			m[child].push_back(parent); 
		}
		buildMap(child,child->left);
		buildMap(child,child->right);
	}
    
private:
	unordered_map<TreeNode* , vector<TreeNode*> > m;
	vector<int> ans;
};


int main(){


	return 0;
}

