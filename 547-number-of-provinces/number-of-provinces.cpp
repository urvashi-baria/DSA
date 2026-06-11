class Solution {
    void dfs(int curr,vector<bool>& vis,vector<vector<int>>&adj){
        vis[curr] = true;
        for(int neighbour:adj[curr]){
            if(vis[neighbour]==false){
                dfs(neighbour,vis,adj);
            }
        }   
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>vis(n);
        int c = 0;
        for(int i = 0;i<n;i++){
            if(vis[i]==false){
                dfs(i,vis,adj);
                c++;
            }
        }
        return c;
    }
};