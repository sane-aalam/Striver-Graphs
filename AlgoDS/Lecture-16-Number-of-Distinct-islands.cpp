
#include <bits/stdc++.h>
using namespace std;

//* hard questions -use mathmatically tricks
// [result points] = [current points] - [base points]

class Solution {
  private:
    void DFS(int row, int col,vector<vector<int>>& grid,
    vector<vector<int>>& vis,int baserow,int basecol, vector<pair<int,int>>&store){
        
          // mark visted and push into the vector 2-D matrix
        vis[row][col] = 1;
        store.push_back({row-baserow,col-basecol});
        
        int delrow[4] = { -1,0,1,0};
        int delcol[4] = { 0,1,0,-1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        // Go to the 4-directions 
        for(int direction = 0; direction < 4; direction ++){
            int newrow = row + delrow[direction]; 
            int newcol = col + delcol[direction];
            
            // must follow three condtion - valid range of the matrix + not already visted + it is land (1)
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m
            && grid[newrow][newcol] == 1 && vis[newrow][newcol] == 0){
                DFS(newrow,newcol,grid,vis,baserow,basecol,store);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                vector<pair<int,int>> store;
                if(grid[row][col] == 1 && vis[row][col] == 0){
                    DFS(row,col,grid,vis,row,col,store);
                    st.insert(store);
                }
            }
        }
        return st.size();
    }
};

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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}