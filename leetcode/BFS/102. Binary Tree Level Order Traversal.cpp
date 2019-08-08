#include<iostream>
#include<vector> 
#include<queue>
using namespace std;
//参考他人的代码后进行的改进
//摒弃了自己重新创建结构体的想法，树的层次会进行记录 

struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if(root==NULL){
        	return v;
		}
		queue<TreeNode*> q;
		q.push(root);
		//临时指针，提供中间空间 
		TreeNode *t;
		//按层次进行循环 
		while(!q.empty()){
			vector<int> vt;
			int size=q.size();
			for(int i=0;i<size;i++){
				t=q.front();
				//将当前节点的值放入vector
				vt.push_back(t->val); 
				q.pop();
				//扩展当前节点t 
				if(t->left!=NULL){
					q.push(t->left);
				}
				if(t->right!=NULL){
					q.push(t->right);
				}
			}
			//将该层节点值放入答案中
			v.push_back(vt); 
		}
		return v; 
		
    }
};

int main(){
	
	
	
	
	
	return 0;
}
