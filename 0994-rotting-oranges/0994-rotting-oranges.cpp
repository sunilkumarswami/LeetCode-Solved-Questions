class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            if(size) ans++;
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(i+1<n && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j+1<m && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        if(ans>0) return ans-1;
        return ans;
    }
};