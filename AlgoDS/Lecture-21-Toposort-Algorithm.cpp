#include <bits/stdc++.h>
using namespace std;


//* remember this algorithm using the way
// When something is appear before something called toposort algorithm
// u appear before v
// student1 inter the class before student 2
// task1 done before task 2 


class Solution
{
    private:
    void CallDFS(int node, vector<int>& vis, stack<int> & st, vector<int> adj[]){
        
        // those who complete thier DFS call push into the stack
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                CallDFS(it,vis,st,adj);
            }
        }
        
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> st;
	    
	    for(int node = 0; node < V; node++){
	        if(!vis[node]){
	            CallDFS(node,vis,st,adj);
	        }
	    }
	    
	    
	    // copy the all the nodes into the vector with help of the stack 
	    vector<int> result;
	    while(!st.empty()){
	        int node = st.top();
	        result.push_back(node);
	        st.pop();
	    }
	    
	    return result;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
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