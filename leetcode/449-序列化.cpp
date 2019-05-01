#include<iostream>
#include<sstream>
#include<string>
using namespace std;


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 
class Codec {
public:
	string i2s(int x){
		stringstream sstr;
		string str;
		sstr<<x;
		sstr>>str;
		return str;
	}
	
	int s2i(string s){
		stringstream sstr;
		int x;
		sstr<<s;
		sstr>>x;
			return x;
	}
	
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return tostring(root); 
    }
	
	string tostring(TreeNode* root){
		if(!root) return "#!";
		string str;
		str=i2s(root->val)+"!"+tostring(root->left)+tostring(root->right);
		return str;
	}
	
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return toroot(data);
    }
    
    int index=0;
    
    TreeNode* toroot(string data){
		if(data.substr(index,2)=="#!"){
			index+=2;
    		return NULL;
		}
		int t=index+1;
		while(data[t]!='!'){
			t++;
		}
		int l=t-index;
		TreeNode* root=new TreeNode(s2i(data.substr(index,l)));
		index=t+1;
		root->left=toroot(data);
		root->right=toroot(data);
		return root;
	}
    
};

void poster(TreeNode *root){
	if(!root){
		return;
	}
	cout<<root->val<<endl;
	poster(root->left);
	poster(root->right);
}

int main(){
	TreeNode *root=new TreeNode(113);
	root->left=new TreeNode(22);
	root->right=new TreeNode(44);
	root->left->left=new TreeNode(44);
	root->right->left=new TreeNode(22);
	root->right->left->left=new TreeNode(44);
	root->right->left->right=new TreeNode(33);	
	
	Codec s;
	string ans;
	ans=s.serialize(root);
	cout<<ans<<endl;
	TreeNode *r=s.deserialize(ans);
	poster(r);
	
	
	return 0;
}

