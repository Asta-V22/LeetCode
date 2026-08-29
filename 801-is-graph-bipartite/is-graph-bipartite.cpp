class Solution {
private:
    bool dfs(vector<vector<int>> &graph, int curr, vector<int> &color, int currcolor){
        color[curr] = currcolor;

        for(int &v: graph[curr]){
            if(color[v]==currcolor){
                return false;
            }
            if(color[v]==-1){
                int newcolor = 1 - currcolor;
                if(!dfs(graph, v, color, newcolor)) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N,-1);    //marked not colored at the beginning

        //let us keep 2 colors as 0 and 1

        for(int i=0; i<N; i++){
            if(color[i]==-1){
                if(!dfs(graph, i, color, 0)){
                    return false;
                }
            }
        }

        return true;
    }
};