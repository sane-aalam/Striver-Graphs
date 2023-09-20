#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
       queue<int> Queue;
       vector<int> result;
       // create visited array
       vector<int> visted(V,0);
    
       Queue.push(0);
       visted[0] = 1;
       
       // for your understanding, while run until your queue is not gonna empty
       while(!Queue.empty()){
           int current_node = Queue.front();
           Queue.pop();
           
           // push into the result array graph node
           result.push_back(current_node);
           
           // go the adjlist node 
           for(auto connectnode : adj[current_node]){
               // if conncet node is not already visted you have to push into queue 
               // you maintan visited array 
               // you can mark visted 
               if(visted[connectnode] == 0){
                   Queue.push(connectnode);
                   visted[connectnode] = 1;
               }
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}