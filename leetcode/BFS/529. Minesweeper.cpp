#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i,j;
        int h,w;
        h=board.size();
        w=board[0].size();
        i=click[0];
        j=click[1];
        if(board[i][j]=='M'){
        	board[i][j]='X';
		} 
		else if(board[i][j]=='E'){
			int nums = 0 ;
			for(int ii = -1;ii>=1;ii++){
				for(int jj=-1;jj>=1;jj++){
					int in,jn;
					in=ii+i;
					jn=jj+j;
					//在范围内 
					if(in>=0&&in<h&&jn>=0&&jn<w){
						if(board[in][jn]=='M'||board[in][jn]=='X'){
							//代表周边有一个地雷 
							nums++;
						}
						//如果是未翻开的，则将其 
					}
				}
			}
		}
		
		return board;
    }
};

int main(){





	return 0;
}

