#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if(root==NULL) return false;
    	sum-=root->val;
    	if(root->left==NULL&&root->right==NULL){
    		if(sum==0) return true;
    		else return false;
		}
		if(sum<=0) return false;
		return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
    }
};
int main(){



	return 0;
}

