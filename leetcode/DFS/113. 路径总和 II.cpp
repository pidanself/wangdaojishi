#include<iostream>
#include<vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<int> temp;
        pathSum(root,temp,sum);
        return result;
    }
    
    void pathSum(TreeNode* root,vector<int> temp,int res){
    	if(root==NULL) return;
    	res-=root->val;
    	temp.push_back(root->val);
    	if(root->left==NULL&&root->right==NULL){
    		if(res==0){
    			result.push_back(temp);
			}
			else{
				return ;
			}
		}
		pathSum(root->left,temp,res);
        pathSum(root->right,temp,res);
	}
private:
	vector<vector<int> > result;
};


int main(){


	return 0;
}

