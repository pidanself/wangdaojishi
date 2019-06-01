#include<iostream>
#include<vector> 
#include<stack>
using namespace std;

struct TreeNode {
	int val;
   	TreeNode *left;
   	TreeNode *right;
   	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

stack<TreeNode*> s[2];
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        int h=1;
        vector<vector<int> > ans;
        if(root==NULL){
        	return ans;
		}
		else{
			vector<int> r;
			r.push_back(root->val);
			if(root->left!=NULL) s[1].push(root->left);
			if(root->right!=NULL) s[1].push(root->right);
			h++;
			ans.push_back(r);
		}
		
		while(s[0].size()!=0||s[1].size()!=0){
			if(h%2==0){
				vector<int> t;
				while(s[1].size()!=0){
					TreeNode *tem=s[1].top();
					s[1].pop();
					t.push_back(tem->val);
					if(tem->right!=NULL) s[0].push(tem->right);
					if(tem->left!=NULL) s[0].push(tem->left);
					
				}
				ans.push_back(t);
			}
			else{
				vector<int> t;
				while(s[0].size()!=0){
					TreeNode *tem=s[0].top();
					s[0].pop();
					t.push_back(tem->val);
					if(tem->left!=NULL) s[1].push(tem->left);
					if(tem->right!=NULL) s[1].push(tem->right);
				}
				ans.push_back(t);
			}
			h++;
		}
		return ans;
		
    }  
};

int main(){



	return 0;
}

