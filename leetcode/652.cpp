#include<iostream>
#include<vector>
#include<map>
#include<sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> result;
		map <string,int> m;
        helper(root,result,m);
        return result;
        
    }
    string to_string(int x){
    	stringstream sstr;
    	string str;
    	sstr<<x;
    	sstr>>str;
    	return str;
	}
    //二叉树的序列化
    string helper(TreeNode *root,
	vector<TreeNode *> &result,
	map <string,int>&m){
		string str;
		if(!root) return "#";
		str=to_string(root->val)+helper(root->left,result,m)+
		helper(root->right,result,m);
		if(m[str]==1) result.push_back(root);
		m[str]++;
		return str;
	}
};

int main(){
	Solution s;
	
	s.findDuplicateSubtrees();


	return 0;
}

