#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//使用h标记层次 
struct TreeNodeH{
	TreeNode * t;
	int h;
};
class Solution {
public:
	//使用h标记层次 ，代码复杂，时间消耗较小 
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> ans;
    	if(root==NULL){
    		return ans;
		}
    	queue<TreeNodeH> q;
    	//初始化 
    	TreeNodeH rootH;
    	rootH.t=root;
    	rootH.h=1;
    	q.push(rootH);
    	
    	while(!q.empty()){
    		TreeNodeH treeNodeH = q.front();
    		//对该节点进行扩展
			if(treeNodeH.t->left!=NULL){
				TreeNodeH t1;
				t1.t=treeNodeH.t->left;
				t1.h=treeNodeH.h+1;
				q.push(t1);
			} 
			if(treeNodeH.t->right!=NULL){
				TreeNodeH t1;
				t1.t=treeNodeH.t->right;
				t1.h=treeNodeH.h+1;
				q.push(t1);
			} 
			
    		q.pop();
    		if(q.empty()){
    			ans.push_back(treeNodeH.t->val);
    			continue;
			}
			else{
				if(treeNodeH.h==q.front().h-1){
					ans.push_back(treeNodeH.t->val);
				}
			}
			
		}
		return ans;
    }
    //不使用h标记层次，代码更简洁，但时间消耗更多 
    vector<int> rightSideView1(TreeNode* root) {
        vector<int> ans;
		if(root==NULL) return ans;
		queue<TreeNode *> q;
		q.push(root);
		while(!q.empty()){
			int size = q.size();
			for(int i = 0 ; i < size ; i++){
				if(i == size - 1){
					ans.push_back(q.front()->val);
				}
				if(q.front()->left != NULL){
					q.push(q.front()->left);
				}
				if(q.front()->right != NULL){
					q.push(q.front()->right);
				}
				q.pop(); 
			}
		} 
		return ans;
    }
};



int main(){

	return 0;
}

