#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int h,w;
    vector<vector<char> > updateBoard(vector<vector<char> >& board, vector<int>& click) {	
		//ªÒ»°√‘π¨∏ﬂøÌ
		h=board.size();
		w=board[0].size();
		
		bfs(board,click[0],click[1]);
		
		return board;
    }
    
    void bfs(vector<vector<char> >& board,int n,int m){
    	if(board[n][m]=='M'){
    		board[n][m]='X';
    		return ;
		}
		else if(board[n][m]=='E'){
			int nums=0;
	    	for(int i=n-1;i<=n+1;i++){
	    		for(int j=m-1;j<=m+1;j++){
	    			if(i>=0&&i<h&&j>=0&&j<w){
	    				if(board[i][j]=='X'||board[i][j]=='M'){
		    				nums++;
						}
					}
				}
			}
			if(nums==0){
				board[n][m]='B';
				for(int i=n-1;i<=n+1;i++){
	    		for(int j=m-1;j<=m+1;j++){
	    			if(i>=0&&i<h&&j>=0&&j<w){
	    				if(board[i][j]=='X'||board[i][j]=='M'){
		    				bfs(board,i,j);
						}
					}
				}
			}
			}
			else{
				board[n][m]='0'+nums;
				return;
			} 
		}
    	
	}
};

int main(){


	return 0;
}

