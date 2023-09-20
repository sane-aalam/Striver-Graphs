#include <bits/stdc++.h>
using namespace std;

//* -> Step by step to solve this problem 
/* very simple hay ---
 step-1 convert matrix into adjlist way
 step-2 call dfs algorithm 
 step-3 count how many nubmer of provices 
*/

class Solution {
  private:
  // DFS algorithm function 
   void dfs(int node,vector<int>& vis,vector<int> newAdj[]){
       
       vis[node] = 1;
       
       for(auto it : newAdj[node]){
           if(vis[it] == 0){
               dfs(it,vis,newAdj); // recursive call until you have traversal 
           }
       }
   }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
       
       // step-1 convert matrix into adjlist way
        vector<int> newAdj[V];
        
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j] == 1 && i != j){
                    // u-v
                    // v-u 
                    newAdj[i].push_back(j);
                    newAdj[j].push_back(i);
                }
            }
        }
        
       //  step-2 call dfs algorithm 
        vector<int> vis(V,0);
        int count = 0;
        
        for(int node = 0; node < V; node++){
            if(vis[node] == 0){
                dfs(node,vis,newAdj);
                count = count + 1;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}