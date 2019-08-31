#include<iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
    	int res=0;
    	if(root==NULL) return res;
    	res+=paths(root,sum);
    	res+=pathSum(root->left,sum);
    	res+=pathSum(root->right,sum);
    	return res;
    }
    
    int paths(TreeNode* root,int sum){
    	if(root==NULL) return 0;
    	sum-=root->val;
    	int res=0;
    	if(sum==0) res++;
    	res+=paths(root->left,sum);
    	res+=paths(root->right,sum);
    	return res;
	}
};

int main(){


	return 0;
}

