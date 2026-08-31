class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent==y_parent){
            return;
        }
        else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }

        for(auto &x: edges){
            int parent0 = find(x[0]);
            int parent1 = find(x[1]);

            if(parent0 != parent1){
                Union(x[0],x[1]);
            }
        }

        map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[find(i)]++;
        }

        long long remaining = n;

        long long result = 0;

        for(auto &it : mp){
            long long size = it.second;
            result +=size*(remaining-size);
            remaining-=size;
        }
        return result;


    }
};