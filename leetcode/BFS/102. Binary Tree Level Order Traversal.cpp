#include<iostream>
#include<vector> 
#include<queue>
using namespace std;
//�ο����˵Ĵ������еĸĽ�
//�������Լ����´����ṹ����뷨�����Ĳ�λ���м�¼ 

struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if(root==NULL){
        	return v;
		}
		queue<TreeNode*> q;
		q.push(root);
		//��ʱָ�룬�ṩ�м�ռ� 
		TreeNode *t;
		//����ν���ѭ�� 
		while(!q.empty()){
			vector<int> vt;
			int size=q.size();
			for(int i=0;i<size;i++){
				t=q.front();
				//����ǰ�ڵ��ֵ����vector
				vt.push_back(t->val); 
				q.pop();
				//��չ��ǰ�ڵ�t 
				if(t->left!=NULL){
					q.push(t->left);
				}
				if(t->right!=NULL){
					q.push(t->right);
				}
			}
			//���ò�ڵ�ֵ�������
			v.push_back(vt); 
		}
		return v; 
		
    }
};

int main(){
	
	
	
	
	
	return 0;
}
