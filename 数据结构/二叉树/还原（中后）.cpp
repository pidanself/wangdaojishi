//还原二叉树
//已知中序遍历和后序遍历
//求前序遍历 
#include<iostream>
#include<cstring>
using namespace std;
//定义节点 
struct node{
	node *lchild=NULL;
	node *rchild=NULL;
	char v;
}; 

//前序遍历
void preorder(node *r){
	if(r==NULL){
		return;
	}
	cout<<r->v;
	if(r->lchild!=NULL){
		preorder(r->lchild);
	}
	if(r->rchild!=NULL){
		preorder(r->rchild);
	}
}
//1存放中序，2存放后序 
char str1[30],str2[30];
//还原函数
node *restore(int s1,int e1,int s2,int e2){
	node *rr=new node;
	rr->v=str2[e2];
	if(s1==e1){
		return rr;
	}
	int s11,e11,s21,e21,s12,e12,s22,e22;
	
	for(int i=s1;i<=e1;i++){
		if(str1[i]==str2[e2]){
			s11=s1;
			e11=i-1;
			s12=i+1;
			e12=e1;
			s21=s2;
			e21=s2+i-s1-1;
			s22=s2+i-s1;
			e22=e2-1;
			break;
		}
	}
	
	
	rr->lchild=restore(s11,e11,s21,e21);
	rr->rchild=restore(s12,e12,s22,e22);
	
	
	return rr; 
} 
 
int main(){
	node *root;
	cin>>str1>>str2;
	root=restore(0,strlen(str1)-1,0,strlen(str2)-1);
	preorder(root);

	return 0;
}

