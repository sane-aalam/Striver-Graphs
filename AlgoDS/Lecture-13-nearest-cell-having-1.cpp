
 /*  simple appraoch to solve this type Question
     same to same **rottern orgrans**
        
        case 1 :
        
        need a queue data structure 
        need a visited 2-d array
        fil the all 1's into the queue with distance (step 1) and mark visted using visted matrix
        
        
        case 2 :
        pop the nodes into the queue usig BFS traversal
        convert this cell element into steps taken
        go the 4-directions 
        checkout the it is valid range and it is not visited
 */
	
    
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	  
	   int n = grid.size();
	   int m = grid[0].size();
	   
	   queue<pair<int,pair<int,int>>> q;
	   vector<vector<int>> vis(n,vector<int>(m,0));
	   
	   // case 1 : push all 1's into the queue and mark visted 
	   for(int i = 0; i<n; i++){
	       for(int j = 0; j<m; j++){
	           if(grid[i][j] == 1){
	               q.push({0,{i,j}});
	               vis[i][j] = 1;
	           }
	       }
	   }
	   
	   
	   // go the all the neighbours node and mark visted 
	   while(!q.empty()){
	       int steps = q.front().first;
	       int row = q.front().second.first;
	       int col = q.front().second.second;
	       
	       q.pop();
	       
	       grid[row][col] = steps;
	       
	       // go the 4-directions
	       int delrow[] = {-1,0,1,0};
	       int delcol[] = { 0,1,0,-1};
	       
	       for(int index = 0; index < 4; index ++){
	           int newrow = row + delrow[index];
	           int newcol = col + delcol[index];
	           
	           if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol]){
	               q.push({steps+1,{newrow,newcol}});
	               vis[newrow][newcol] = 1;
	           }
	           
	       }
	   }
	   return grid;
	}
};


//{ Driver Code Starts.
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}