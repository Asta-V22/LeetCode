class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //lets make an adjacency list of prequisites
        vector<vector<int>> adj(numCourses);

        //indegree of the edges
        vector<int> indegree(numCourses);

        for(auto &x : prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        //now i will check wether there exists a cycle in the graph or not
        //kahn's algorithm

        //first put all the edges with indegree 0 in the queue
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int edge = q.front();
            q.pop();
            count++;

            for(int &x : adj[edge]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }

        return count==numCourses;
    }
};