class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //making adj, indegree
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for(auto &x : prerequisites){          // 0--->1
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count = 0;
        vector<int> topo;

        while(!q.empty()){
            auto edge = q.front();
            q.pop();
            topo.push_back(edge);
            count++;

            for(int &x : adj[edge]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }

        if(count!=numCourses){
            return {};
        }

        return topo;

    }
};