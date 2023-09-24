#include <bits/stdc++.h>
using namespace std;


//* remember this algorithm using the way
// When something is appear before something called toposort algorithm
// u appear before v
// student1 inter the class before student 2
// task1 done before task 2 

//* Those who can complete their DFS call put into the stack
// remember one things when use this algorithm - 
// whenever something apear before something,think about this particular algorithm


class Solution
{
    private:
    // you have to understand this concept 
    // call by reference 
    // call by value 
    void DFS(int node, vector<int> & vis,stack<int>&Stack,vector<int> adj[]){
        
        // you have to mark visted the node
        vis[node] = 1;
        
        for(auto connectedNode : adj[node]){
            if(vis[connectedNode]  == 0){
                DFS(connectedNode,vis,Stack,adj);
            }
        }
        
        // when DFS call complete push into the stack
        // backtracking concept used here
        Stack.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> result;
	    stack<int> Stack;
	    vector<int> vis(V,0);
	    
	    for(int node = 0; node<V; node++){
	        if(vis[node] == 0){
	            // call the dfs with stack
	            DFS(node,vis,Stack,adj);
	        }
	    }
	    
	    // now you can push stack element into Result vector
	    
	    while(!Stack.empty()){
	        int node = Stack.top();
	        result.push_back(node);
	        Stack.pop();
	    }
	    
	    return result;
	}
};


/*---------------------  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends