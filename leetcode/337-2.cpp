#include<iostream>
#include<map> 
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x):val(x),left(NULL),right(NULL){
	 
	 }
};


class Solution {
public:
	map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        return tryrob(root);
    }
    
    int tryrob(TreeNode* root){
    	if(!root) return 0;
    	if(m.count(root)!=0) return m[root];
		
		int res1=0,res2=0;
		//尝试偷取本节点
		res1=root->val;
		if(root->left){
			res1+=tryrob(root->left->right)+tryrob(root->left->left);
		}
		if(root->right){
			res1+=tryrob(root->right->left)+tryrob(root->right->right);
	
		}
		//尝试不偷取本节点 
		res2+=tryrob(root->left)+tryrob(root->right);
		
		res1=max(res1,res2);
		m[root]=res1;
		return m[root];
	}
    
};

int main(){
	
	


	return 0;
}

