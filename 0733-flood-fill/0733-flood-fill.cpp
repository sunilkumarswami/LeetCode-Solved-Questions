class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        int n=image.size(),m=image[0].size();
        if(old==color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            
            for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==old){
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
            }
        }
        return image;
    }
};