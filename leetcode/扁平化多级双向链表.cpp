#include<iostream>
#include<stack> 
using namespace std;
	
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
stack<Node*> s;
class Solution {
public:
    Node* flatten(Node* head) {
        Node* t=head;
		while(t!=NULL){
			if(t->child!=NULL){
				if(t->next!=NULL){
					s.push(t->next);
					t->next=t->child;
					t->child->prev=t;
					t->child=NULL;
					t=t->next;
				
				}
				else{
					t->next=t->child;
					t->child->prev=t;
					t->child=NULL;
					t=t->next;
				}
			}
			else{
				if(t->next==NULL){
					if(!s.empty()){
						t->next=s.top();
						s.top()->prev=t;
						t=t->next;
						s.pop();	
					}
					else{
						t=NULL;
					}
				}
				else{
					t=t->next;
				}
			}
		} 
		return head;
    }
};	

int main(){



}

