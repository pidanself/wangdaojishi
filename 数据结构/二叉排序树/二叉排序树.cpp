#include<iostream>
using namespace std;

struct node{
	node *lchild=NULL;
	node *rchild=NULL;
	int i;
};

node *root=NULL;

node *insert(node *r,int x){
	if(r==NULL){
		r=new node;
		r->i=x;
		return r;
	}
	
	if(x<=r->i){
		r->lchild=insert(r->lchild,x);
	}
	else{
		r->rchild=insert(r->rchild,x);
	}
	
	return r;
}


void inorder(node *r){
	if(r->lchild!=NULL){
		inorder(r->lchild);
	}
	cout<<r->i<<" ";
	if(r->rchild!=NULL){
		inorder(r->rchild);
	}
}
//前序遍历 
preorder(node *r){
	cout<<r->i<<" ";
	if(r->lchild!=NULL){
		preorder(r->lchild);
	}
	
	if(r->rchild!=NULL){
		preorder(r->rchild);
	}
}

//后序遍历 
postorder(node *r){
	
	if(r->lchild!=NULL){
		postorder(r->lchild);
	}
	
	if(r->rchild!=NULL){
		postorder(r->rchild);
	}
	cout<<r->i<<" ";
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		root=insert(root,t);
	}
	
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	

	return 0;
}

