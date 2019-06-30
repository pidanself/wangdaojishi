#include<iostream>
using namespace std;

struct node{
	node *lchild=NULL;
	node *rchild=NULL;
	int c;
};


node *ins(node *root,int num){
	if(root==NULL){
		root=new node;
		root->c=num;
	}
	else{
		if(num<=root->c){
			//插入左子树
			root->lchild=ins(root->lchild,num);
		}
		else{
			//插入右子树 
			root->rchild=ins(root->rchild,num);
		}
	}
	return root;
}

void preOrder(node *root){
	cout<<(root->c)<<" ";
	if(root->lchild!=NULL){
		preOrder(root->lchild);
	}
	if(root->rchild!=NULL){
		preOrder(root->rchild);
	}
}

void midOrder(node *root){
	
	if(root->lchild!=NULL){
		midOrder(root->lchild);
	}
	cout<<root->c<<" ";
	if(root->rchild!=NULL){
		midOrder(root->rchild);
	}
}

void postOrder(node *root){
	if(root->lchild!=NULL){
		postOrder(root->lchild);
	}
	if(root->rchild!=NULL){
		postOrder(root->rchild);
	}
	cout<<root->c<<" ";
}


int main(){
	int n;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		root=ins(root,t);
	}
	
	preOrder(root);
	cout<<endl;
	midOrder(root);
	cout<<endl;
	postOrder(root);

	return 0;
}

