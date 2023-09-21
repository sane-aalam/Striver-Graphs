#include<bits/stdc++.h>
using namespace std;

//* DAY01 TASK-
//* last tak puri mehnat karni hai 

class Solution {
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,pair<int,int>>> Queue;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // step-1 collect all the alredy rottern organes into the queue 
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 2){
                    Queue.push({0,{row,col}});
                    vis[row][col] = 1;
                }
            }
        }
        
        
        // step-2 apply BFS algorithm
        
        int maxiTime = 0;
        
        while(!Queue.empty()){
            auto cell = Queue.front();
            
            int time = cell.first;
            int row = cell.second.first;
            int col = cell.second.second;
            
            maxiTime = max(time,maxiTime);
            
            Queue.pop();
            
            //A rotten orange at index [i,j] can rot other fresh orange at 
            //indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            
            for(int direction = 0; direction < 4; direction++){
                int newrow = row + delrow[direction];
                int newcol = col + delcol[direction];
                
                
                // maintain three condtion - valid range + not alredy rottern + have fresh oranges
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
                && vis[newrow][newcol] == 0 && grid[newrow][newcol] == 1){
                    Queue.push({time+1,{newrow,newcol}});
                    // rottern the organes and mark visted
                    grid[newrow][newcol] = 2;
                    vis[newrow][newcol] = 1;
                }
            }
        }
        
      //----------------------------------------------------       
         //* Error Fix - TEST CASE 
        // after the rottern all the orgrans - FRESH all 
        // If not possible returns -1.
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                 if(grid[row][col]==1){
                        return -1;
                }
            }
        }
      //----------------------------------------------------   
        return maxiTime;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}