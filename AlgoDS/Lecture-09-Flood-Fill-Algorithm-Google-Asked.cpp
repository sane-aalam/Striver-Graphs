#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>> Queue;
        Queue.push({sr,sc});
        
        // don't want to chnage orginal data 
        vector<vector<int>>colormatix = image;
        // convert into the newcolor
        colormatix[sr][sc] = newColor;
        int startColor = image[sr][sc];
    
        while(!Queue.empty()){
            int row = Queue.front().first;
            int col = Queue.front().second;
            Queue.pop();
            
            // we can go 4- directionally to those pixles ( also with the same color starting color)
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int index = 0; index < 4; index++){
                int newrow = delrow[index] + row;
                int newcol = delcol[index] + col;
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && 
                colormatix[newrow][newcol] != newColor && image[newrow][newcol] == startColor){
                    Queue.push({newrow,newcol});
                    colormatix[newrow][newcol] = newColor;
                }
            }
        }
        return colormatix;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}