class Solution {
    int n;
private:
    void dfs(vector<vector<int>>& isConnected, vector<int> &vis, int u){
        vis[u]=1;     //mark u as visited

        //now check for other edges connected with u but not visited yet
        for(int v = 0; v<n; v++){
            if(!vis[v] && isConnected[u][v]==1){
                dfs(isConnected, vis, v);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //we can do this by making our own adjacency list as well as using the given one
        n = isConnected.size();
        vector<int> vis(n);

        int prov  = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                prov++;
            }
        }

        return prov;
    }
};