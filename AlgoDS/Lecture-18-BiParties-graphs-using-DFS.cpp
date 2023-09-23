#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int start, int col, vector<int>adj[], vector<int>&color){
      
       color[start] = col;

    // it can convert ture into false 
    // 1 into 0 and 0 into 1 
    //  !operator
    //    1 = 0
    //    0 = 1
       
       for(auto x : adj[start]){
        // if it is not colored 
           if(color[x] == -1){
            // colored with opsite color
            //    col = !col; use can also use this 
               if(dfs(x,!col,adj,color) == false){
                   return false;
               }
           }
           else if(color[x] == col){
               return false;
           }
       }
       return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	 
	 vector<int>color(V,-1);
	 
	 for(int i = 0; i<V;i++){
	     if(color[i] == -1){
	         if(dfs(i,0,adj,color) == false){
	             return false;
	         }
	     }
	 }
	 return true;
	}
};