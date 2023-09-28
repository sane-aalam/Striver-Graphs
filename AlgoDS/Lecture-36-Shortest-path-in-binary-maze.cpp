
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // size of the grid row wise and colum wise 
        int n = grid.size();
        int m = grid[0].size();

        // Edages case - what is scouce node is not zero and destination node is not zero 
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        // push into the queue 
        // mark visted this particular cell 
        q.push({1,{0,0}});
        vis[0][0] = 1;

        int ans = INT_MAX;

        while(!q.empty()){
            int path = q.front().first;
            int row  = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            // if scouce are equal to distincation then return -
            // The length of a clear path is the number of visited cells of this path.
            if(row == n-1 && col == m-1){
                return min(path,ans);
            }

            // Traveral the 8-directions
            //  up down left right uprd drdl upld dldl

            // it is hard to understand, use paper and pen to create table to understand
            // Thank you!
            int delrow[8] = {-1,1,0,0,-1, 1, -1, 1};
            int delcol[8] = {0,0,-1,1, 1, 1, -1, -1}; 

            for(int i = 0; i<8; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if(newrow >= 0 && newrow <n && newcol >= 0 && newcol < m && 
                !vis[newrow][newcol] && grid[newrow][newcol] == 0){
                    vis[newrow][newcol] = 1;
                    q.push({path+1,{newrow,newcol}});
                }
            }
        }
        return -1;
    }
};












