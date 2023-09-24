//User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
    // ------------- by khans algorithim (bfs)
    
	   // - create the adj list 
	   // - set the indegree of the every node
	   // - push into the queue which have indegree 0
	   // - when we will pop the node checkout the who are the adjcecny node redure the indegree of these nodes
	   // by chance anyone have indegree 0, then push into the queue data strutrue 
	    
	   // + remember the point - you have to point the element then store the element into the vector ans result array
	    
	    int N = n;
	    
	   // 1. step - create the adj list
	    vector<int> adj[N];
	    for(auto it : prerequisites){
            // gonna complete task-2 -> task-1
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    
        // simple KHAN'S Algorithm used here - simple 
	    int indegree[N] = {0};
	    vector<int> ans;
	    queue<int> q;
	    
	    for(int i = 0; i<N; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i = 0; i<N; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            
	             if(indegree[it] == 0) {
	                q.push(it);
	             }
	        }
	    }
	    
	    // if answer array size is equal to give nodes size then you are able to perfom the complete task
	    if(ans.size() == N){
	        return ans;
	    }
	    return {};
	    
    }
};