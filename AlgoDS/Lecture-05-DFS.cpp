#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
  
   // we will cover left depth,then go the right depth 
   // we can use recursion----
   void dfs(int node, vector<int> & visted, vector<int> & result,vector<int> adj[]){
       
       visted[node] = 1;
       result.push_back(node);
       
       // go the adjlist 
       for(auto conncetcode : adj[node]){
           if(visted[conncetcode] == 0){
               dfs(conncetcode,visted,result,adj);
           }
       }
   }
   
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visted(V,0);
        // here result vector contain traversal of the complete graphs using depth first search
        vector<int> result;
        
        // starting from the 0th vertex from left to right according to the graph.
        for(int node = 0; node < V; node++){
            if(visted[node] == 0){
                dfs(node,visted,result,adj);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}