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
        //������תͼ
		buildMap(NULL,root);
		
		//��ͼ���п�������������ݹ飩
		dfs(NULL,target,K);
		
		//���ش�
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
    		//������ڵ���ڼ���m��
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

