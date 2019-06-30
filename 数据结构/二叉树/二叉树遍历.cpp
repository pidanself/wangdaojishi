#include<iostream>
using namespace std;
string pres;
string mids;

struct node{
	node *lchild=NULL;
	node *rchild=NULL;
	char c;
}; 


node *build(int s1,int e1,int s2,int e2){
	node *root=new node;
	root->c=pres[s1];
	int index=s2;
	while(index<=e2){
		if(pres[s1]==mids[index]){
			break;
		}
		else{
			index++;
		}
	}
	//有左子树 
	if(index!=s2){
		root->lchild=build(s1+1,s1+index-s2,s2,index-1);
	}
	//有右子树
	if(index!=e2){
		root->rchild=build(s1+index-s2+1,e1,index+1,e2);
	} 
	return root;
}

void postOrder(node *root){
	
	if(root->lchild!=NULL){
		postOrder(root->lchild);
	}
	if(root->rchild!=NULL){
		postOrder(root->rchild);
	}
	cout<<root->c;
	
}

int main(){
	cin>>pres>>mids;
	
	node *root=build(0,pres.size()-1,0,mids.size()-1);
	
	postOrder(root);
	return 0;
}

