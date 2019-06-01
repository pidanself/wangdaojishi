#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	ListNode* t=head;
    	if(t==NULL||t->next==NULL){
    		return head;
		}
    	
    	ListNode* tt=t->next;
    	t->next=tt->next;
    	tt->next=t;
    	head=tt;
    	
        while(t->next!=NULL&&t->next->next!=NULL){
        	t=swap(t,t->next,t->next->next);
		}
		
		return head;
    }
    
   	ListNode* swap(ListNode* a,ListNode* b,ListNode* c){
   		a->next=c;
   		b->next=c->next;
   		c->next=b;
   		return b;
	}
};

int main(){



}

