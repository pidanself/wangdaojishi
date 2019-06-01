#include<iostream>
#include<vector> 
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> num;
    vector<int> minl;
    MinStack() {
       
    }
    
    void push(int x) {
        num.push_back(x);
        if(num.size()==1){
        	minl.push_back(0);
		}
		else{
			if(x<num[minl[minl.size()-1]]){
				minl.push_back(num.size()-1);
			}
		}
    }
    
    void pop() {
        num.pop_back();
        
        if(minl[minl.size()-1]==num.size()){
        	minl.pop_back();
		}
    }
    
    int top() {
        return num[num.size()-1];
    }
    
    int getMin() {
        return num[minl[minl.size()-1]];
    }
};



int main(){
	
	
	
	return 0;
} 
