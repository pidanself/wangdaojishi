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
    bool hasPathSum(TreeNode* root, int sum) {
    	if(root==NULL) return false;
    	if(root->left==NULL&&root->right==NULL){
    		if(sum==root->val) return true;
    		else return false;
		}
		else{
			sumG=sum;
	        bool left=hasPathSumP(root->left,root->val);
	        bool right=hasPathSumP(root->right,root->val);
	        return left||right;
		}
    }
    
    bool hasPathSumP(TreeNode* root,int sum){
    	if(root==NULL) return false;
    	sum+=root->val;
    	if(root->left==NULL&&root->right==NULL){
    		if(sum==sumG) return true;
    		else return false;
		}
		bool left=hasPathSumP(root->left,sum);
        bool right=hasPathSumP(root->right,sum);
        return left||right;
	}
    
private:
	int sumG;
};


int main(){


	return 0;
}

