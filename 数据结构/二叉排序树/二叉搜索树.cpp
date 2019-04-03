#include<iostream>
#include<cstring>
using namespace std;
//记录答案 
bool ans[1000]={0};

char str1[30],str2[30];//存储中序与前序遍历合体结果
int ii=0,jj=0;//两个字符串的指针 

struct node{
	char val;
	node *lchild;
	node *rchild;
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

void postorder(node *T,int p){
	if(p==0){
		str1[ii++]=T->val;
		if(T->lchild!=NULL){
			postorder(T->lchild,p);
		}
		if(T->rchild!=NULL){
			postorder(T->rchild,p);
		}
	}
	else{
		str2[jj++]=T->val;
		if(T->lchild!=NULL){
			postorder(T->lchild,p);
		}
		if(T->rchild!=NULL){
			postorder(T->rchild,p);
		}
	}
} 


void inorder(node *T,int p){
	if(p==0){
		str1[ii++]=T->val;
		if(T->lchild!=NULL){
			postorder(T->lchild,p);
		}
		if(T->rchild!=NULL){
			postorder(T->rchild,p);
		}
	}
	else{
		str2[jj++]=T->val;
		if(T->lchild!=NULL){
			postorder(T->lchild,p);
		}
		if(T->rchild!=NULL){
			postorder(T->rchild,p);
		}
	}
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
	int n,m=0;//m代表我们做了多少次判断以便后期输出 
	node *T1=NULL,*T2=NULL;
	while(scanf("%d",&n)!=EOF&&n!=0){
		T1=NULL;T2=NULL;
		char t[12];
		scanf("%s",&t);
		for(int i=0;t[i]!=0;i++){
			T1=insert(T1,t[i]);
		}
		postorder(T1,0);
		inorder(T1,0);
		str1[ii]='\0';
		for(int i=0;i<n;i++){
			char tmp[12];
			scanf("%s",tmp);
			for(int i=0;tmp[i]!=0;i++){
				T2=insert(T2,tmp[i]);
			}
			postorder(T2,1);
			inorder(T2,1);
			str2[jj]='\0';
			if(strcmp(str1,str2)==0){
				ans[m++]=true;
			}
			else{
				ans[m++]=false;
			}
			clear(T2);
			T2=NULL;
			str2[0]='\0';
		}
		clear(T1);
		str1[0]='\0';
		T1=NULL;
	}
	
	for(int i=0;i<m;i++){
		if(ans[i]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

