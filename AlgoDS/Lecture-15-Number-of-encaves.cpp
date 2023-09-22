
//* # Algorithm:
// 1 ) find the all boundry 1"s
// 2 ) traversal the all neigbours mark true - they are on the boundary of the matrix 
// 3 ) which one is not conncected to the boundary then you can simple count the NumberOfEnclaves++;


#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
   void DFS(int row,int col,vector<vector<int>> & vis,vector<vector<int>> & grid){
       
        int n = grid.size();
        int m = grid[0].size();
       
        vis[row][col] = 1;
       
       // Go the 4-direction
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                DFS(nrow,ncol,vis,grid);
            }
            
        }
   }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                // boundary traversal pattern - NEW
                if(row == 0 or row == n-1 or col == 0 or col == m-1){
                    if(grid[row][col] == 1 && vis[row][col] == 0){
                        DFS(row,col,vis,grid);
                        // Call DFS
                        // you can also use BFS Algorithm 
                        // Thank you ! sane
                    }
                }
            }
        }
        
        
        int NumberOfEnclaves = 0;
        for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                // count all 1's which is inside the boundary of the matrix
                if(grid[row][col] == 1 && vis[row][col] == 0){
                    NumberOfEnclaves++;
                }
            }
        }
        return NumberOfEnclaves;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}