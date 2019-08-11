#include<iostream>
#include<queue> 
#include<vector>
#include<limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
        	int size = q.size();
        	int value = INT_MIN ;
        	for(int i=0;i<size;i++){
        		value = max(value,q.front()->val);
        		if(q.front()->left!=NULL){
        			q.push(q.front()->left);
				}
				if(q.front()->right!=NULL){
					q.push(q.front()->right);
				}
				q.pop();
			}
			ans.push_back(value);
		}
		return ans;
    }
};


int main(){





	return 0;
}

