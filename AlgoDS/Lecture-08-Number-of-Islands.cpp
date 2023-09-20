#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   void traversal(int row, int col, vector<vector<int>>&vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        // case1 - create queue data struture and push into the quque and mark visted
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;

        // case2 - go the its' connected 1's all 
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int row = temp.first;
            int col = temp.second;

            // we have to move 4-direction 
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,-1,0,1};

            for(int direction = 0; direction <4; direction++){
                int newrow = delrow[direction] + row;
                int newcol = delcol[direction] + col;

                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m
                && vis[newrow][newcol] == 0 && grid[newrow][newcol] == '1'){
                    q.push({newrow,newcol});
                    vis[newrow][newcol] = 1;
                } 
            }
        } 
   }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        // declare the numberIslands variable for counting the how many islands present
        int NumberIslands = 0;

        // step-1 find the first land then call the BFS/DFS algorithm
        for(int row = 0; row<n; row++){
            for(int col = 0; col <m; col++){
                if(grid[row][col] == '1' && vis[row][col] == 0){
                    NumberIslands++;
                    traversal(row,col,vis,grid);
                }
            }
        }
        return NumberIslands;
    }
};