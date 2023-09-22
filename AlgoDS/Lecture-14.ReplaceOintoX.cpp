#include <bits/stdc++.h>
using namespace std;


//* # Algorithm:
// 1 ) find the all boundry 0"s
// 2 ) traversal the all neigbours mark true
// 3 ) which one is not conncected to the boundary then you can convert into X

class Solution {
private:
    void DFS(int row, int col,vector<vector<int>>&vis,vector<vector<char>>&board){

        // size of the matrix used for manage the traversalling part out the boundary 
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        // check out the left,right,top,bottom 
        // bascially we will be checking 0's neighbours

        // delrow and delcol pattern
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];


        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                    DFS(nrow,ncol, vis, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {

        // size of the matrix used for create new matrix - visted 2-D matrix
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        
        //* 4-directions cover using traversal algorithm - you can use BFS and DFS
        // go the top and down
        // traversal the boundary all side using simple technique
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // all 4-directions
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(!vis[i][j] && board[i][j] == 'O'){
                       DFS(i,j,vis,board);
                    } 
                }
            }
        }

        //* Tum one by one bhi jaa karte ho
        //* top and bottom ki taraf
        //* left and right ki taraf
        //* simple hai 

        // if not visited any 0's
        // simple we can say - onone touched into 0's means' inside the boundary 
        // then we can convert into the nbv 0's -> x's

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};