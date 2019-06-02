#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct N{
	TreeNode *tn;
	int h=0;
};
queue<N> q;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        N t;
        t.tn=root;
        t.h=1;
        q.push(t);
        while(q.empty()==false){
        	N now=q.front();
        	q.pop();
        	if(now.tn->left!=NULL){
        		N tt;
		        tt.tn=now.tn->left;
		        tt.h=now.h+1;
		        q.push(tt);
		        if(tt.h>t.h){
		        	t=tt;
				}
			}
			if(now.tn->right!=NULL){
        		N tt;
		        tt.tn=now.tn->right;
		        tt.h=now.h+1;
		        q.push(tt);
		        if(tt.h>t.h){
		        	t=tt;
				}
			}
		}
		return t.tn->val;
    }
};


int main(){

	S s;
	

}

