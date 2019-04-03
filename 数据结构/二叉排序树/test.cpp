#include<iostream>
using namespace std;
int c=1; 
class node{
	public:
		char val;
		node *lchild;
		node *rchild;
	
		~node(){
			cout<<"我被销毁了"<<c++<<endl;
		}
};


node *insert(node *T,char t){
	if(T==NULL){
		T=new node;
		T->val=t;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else if(T->val>=t){
		
		T->lchild=insert(T->lchild,t);
	}
	else{
		T->rchild=insert(T->rchild,t);
	}
	
	return T;
}

void clear(node *T){
	if(T==NULL){
		return;
	}
	clear(T->lchild);
	clear(T->rchild);
	delete T;
	T==NULL;
}
int main(){
	
	node *t=NULL;
	t=insert(t,'t');
	t=insert(t,'a');
	t=insert(t,'c');
	t=insert(t,'h');
	t=insert(t,'z');
	
	clear(t);

	return 0;
}

