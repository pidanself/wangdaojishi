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
    void flatten(TreeNode* root) {
        TreeNode *pre,*cur;
        cur=root;
        while(cur){
        	if(cur->left){
        		pre=cur->left;
        		while(pre->right) pre=pre->right;
        		pre->right=cur->right;
        		cur->right=cur->left;
        		cur->left=NULL;
			}
			cur=cur->right;
		}
    }
};


int main(){
	


}

