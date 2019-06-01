#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

//前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]

TreeNode *build(vector<int>& preorder, vector<int>& inorder,int s1,int e1,int s2,int e2){	
	if(s1>e1){
		return NULL;
	}
	TreeNode *root=new TreeNode(preorder[s1]);
	int t=preorder[s1];
	int i=0;
	while(true){
		if(inorder[i+s2]==t){
			break;
		}
		i++;
	}	
	root->left=build(preorder,inorder,s1+1,s1+i,s2,s2+i-1);
	root->right=build(preorder,inorder,s1+i+1,e1,s2+i+1,e2);
	return root;
}

int main(){
	vector<int> pr;
	vector<int> in;
	pr.push_back(3);
	pr.push_back(9);
	pr.push_back(20);
	pr.push_back(15);
	pr.push_back(7);
	
	in.push_back(9);
	in.push_back(3);
	in.push_back(15);
	in.push_back(20);
	in.push_back(7);
	
	TreeNode *root=build(pr,in,0,pr.size()-1,0,pr.size()-1);
	
	cout<<root->val;
	cout<<root->left->val;
	cout<<root->right->val;
	return 0;
}
