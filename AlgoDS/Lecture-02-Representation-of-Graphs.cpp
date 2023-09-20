//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
       vector<vector<int>> result(V);
       
       
     //* details explaination
     
    //   for(int i = 0; i<V; i++){
    //       int u = edges[i].first;
    //       int v = edges[i].second;
           
           // u-v direction
           // v-u direction 
    //       result[u].push_back(v);
    //       result[v].push_back(u);
    //   }
    
    
    // short- way to store the matrix 
    for(auto it : edges){
        result[it.first].push_back(it.second);
        result[it.second].push_back(it.first);
    }
       
       return result;
    }
};

// GFG code alredy written
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}