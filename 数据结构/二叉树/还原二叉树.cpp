#include<iostream>
#include<cstring>
using namespace std;

struct Node{
	Node *lchild;
	Node *rchild;
	char c;
};

char str1[30],str2[30];


//二叉树的后序遍历
void postorder(Node *T){
	if(T->lchild!=NULL){
		postorder(T->lchild);
	}
	if(T->rchild!=NULL){
		postorder(T->rchild);
	}
	cout<<T->c;
}

Node *build(int s1,int e1,int s2,int e2){
	
	Node *root=new Node;
	char t=str1[s1];
	int index,i;
	for(i=s2;i<=e2;i++){
		if(str2[i]==t){
			break;
		}
	}
	index=i;
	root->c=t;
	if(index==s2){
		root->lchild=NULL;
	}
	else{
		root->lchild=build(s1+1,s1+(index-s2),s2,index-1);
	}
	
	if(index==e2){
		root->rchild=NULL; 
	}
	else{
		root->rchild=build(s1+(index-s2)+1,e1,index+1,e2);
	}
	return root;
}

int main(){
	
	scanf("%s %s",str1,str2);
	Node *rr=build(0,strlen(str1)-1,0,strlen(str2)-1);
	postorder(rr);


	return 0;
}

