#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *build(vector<int>& inorder, vector<int>& postorder,int s1,int e1,int s2,int e2){
	if(s1>e1){
		return NULL;
	}
	int t=postorder[e2];
	TreeNode *root=new TreeNode(t);
	int i=0;
	int j=0;
	while(true){
		if(inorder[s1+i]==t){
			t=inorder[s1+i+1];
			break;
		}
		i++;
	}
	while(true){
		if(postorder[s2+j]==t){
			break;
		}
		j++;
	}
	
	root->left=build(inorder,postorder,s1,s1+i-1,s2,s2+j-1);
	root->right=build(inorder,postorder,s1+i+1,e1,s2+j,e2-1);
	return root;
}


int main(){
	vector<int> in;
	vector<int> po;
	po.push_back(9);
	po.push_back(15);
	po.push_back(7);
	po.push_back(20);
	po.push_back(3);
	
	
	in.push_back(9);
	in.push_back(3);
	in.push_back(15);
	in.push_back(20);
	in.push_back(7);
	
	
	TreeNode *root=build(in,po,0,po.size()-1,0,po.size()-1);
	
	cout<<root->val;
	cout<<root->left->val;
	cout<<root->right->val;
	
	return 0;
}

