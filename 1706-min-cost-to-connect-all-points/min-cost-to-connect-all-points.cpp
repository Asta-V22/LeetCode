/*----------KRUSKALS--------------------------------*/
class Solution {
    vector<int> parent;
    vector<int> rank;

    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    bool Union(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);

        if(parent_u == parent_v){
            return false;
        }
        else if(rank[parent_u]>rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        else if(rank[parent_v]>rank[parent_u]){
            parent[parent_u] = parent_v;
        }
        else{
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
        return true;
    }

int kruskal(vector<vector<int>> &adj){
    int sum =0;
    for(auto &vec: adj){
        int u = vec[0];
        int v = vec[1];
        int wt = vec[2];

        if(Union(u,v)){
            sum+=wt;
        }
    }
        return sum;
}
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        parent.resize(V);
        rank.resize(V,0);

        for(int i=0; i<V; i++){
            parent[i] = i;
        }
        
        vector<vector<int>> adj;
        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                auto point1 = points[i];
                auto point2 = points[j];

                int wt = abs(point1[0]-point2[0]) + abs(point1[1]-point2[1]);

                adj.push_back({i,j,wt});
            }
        }

        auto comparator = [](const vector<int> &vec1,const vector<int> &vec2){
            return vec1[2]<vec2[2];
        };

        sort(adj.begin(), adj.end(), comparator);

        return kruskal(adj);
    }
};