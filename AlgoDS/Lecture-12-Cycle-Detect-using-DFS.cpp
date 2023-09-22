#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
   bool DFS(int node, int parentNode,vector<int>& visted,vector<int> adj[]){
       
       visted[node] = 1;
       
       for(auto connectNode : adj[node]){
           if(visted[connectNode] == 0){
               // call DFS again 
               if(DFS(connectNode,node,visted,adj)){
                   return true;
               }
           }else if(connectNode != parentNode){
               return true;
           }
       }
       return false;
   }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visted(V,0);
        
        // connceted componets maintan karna hai
        // graph has 0-base indexes 
        for(int node = 0; node < V; node++ ){
            if(visted[node] == 0){
                if(DFS(node,-1,visted,adj) == true){
                    return true;
                }
            }
        }
        
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}