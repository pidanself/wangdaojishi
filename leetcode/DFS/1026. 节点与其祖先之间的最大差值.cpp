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
    int maxAncestorDiff(TreeNode* root) {
        int left=maxAncestorDiff(root->left,root->val,root->val);
        int right=maxAncestorDiff(root->right,root->val,root->val);
        return left>right?left:right;
    }
    
    int maxAncestorDiff(TreeNode* root,int max,int min){
    	if(root==NULL){
    		return 0;
		}
		if(root->val>max){
			max=root->val;
		}
		else if(root->val<min){
			min=root->val;
		}
		
		if(root->left==NULL&&root->right==NULL){
			return max-min;
		}
		
		int left=maxAncestorDiff(root->left,max,min);
        int right=maxAncestorDiff(root->right,max,min);
		
		return left>right?left:right;
	}
};



int main(){


	return 0;
}

