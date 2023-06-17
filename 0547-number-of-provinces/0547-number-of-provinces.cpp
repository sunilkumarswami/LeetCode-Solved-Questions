class Solution {
public:
void dfs(int node,vector<int> a[], int V,vector<int> &vis){
        if(vis[node]) return;
        vis[node]=1;
        for(int v:a[node]){
            if(!vis[v]){
                dfs(v,a,V,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> vis(V+1,0);
        int cnt=0;
        vector<int> a[V];
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(adj[u][v]==1 && u!=v)
                a[u].push_back(v);
            }
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,a,V,vis);
            }
        }
        return cnt;
    }
};