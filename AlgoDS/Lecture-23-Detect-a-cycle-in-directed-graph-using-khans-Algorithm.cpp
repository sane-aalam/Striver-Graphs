#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code start
         // create inDgree Array/Vector for storing the inDgree 
	    vector<int> inDegree(V);
	    
	    // store the all inDgree into the array
	    for(int i = 0; i<V; i++){
	        for(auto it : adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    // create queue data sturucture
	    queue<int>Queue;
	    // check out the which nodes have indegree 0 (zero)
	    for(int i = 0; i<V; i++){
	        if(inDegree[i] == 0){
	            Queue.push(i);
	        }
	    }
	    
	    // create the vector for storing the topo result
	    vector<int>topoArray;
	    
	    // check out the neigbours - who are the adjency nodes
	    while(!Queue.empty()){
	        int node = Queue.front();
	        Queue.pop();
	        
	        // push into the topological sort array - storing the result;
	        topoArray.push_back(node);
	        
	        for(auto it: adj[node]){
	            // reduring the indegree part and check out the indegree which adjency node have 0 
	            // push into the queue data structure
	            inDegree[it] --;
	            if(inDegree[it] == 0){
	                Queue.push(it);
	            }
	        }
	    }
	    
	    
	    //* Node- understand deeply--------------------------
	    // you can only toposot on DAAG
	    // DAAG which don't have any cycle 
	    // if you are able to apply toposort into graphs which means graphs don't have cycle
	    // otherwise graphs have cycle
        //* keep it simeple Feynman Technique ----------------
	    
	    // all cover all the nodes
	    if(topoArray.size() == V) return false;
	    return true;
    }
};