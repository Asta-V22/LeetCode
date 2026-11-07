class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //thought process
        //we'll build two Heap queues that will store the currently idle servers and the busy servers
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> idle;
        priority_queue<tuple<long,int,int> , vector<tuple<long,int,int>>, greater<tuple<long,int,int>>> busy;

        //let us fill in the idle pq (at the start all are idle)
        for(int i=0; i<n; i++){
            idle.push({servers[i],i});
        }

        vector<int> res(m);

        for(int i=0; i<m; i++){
            //first look in the busy to see if someone is getting free
            while(!busy.empty() && get<0>(busy.top())<=i){
                auto [time,server,idx] = busy.top();
                busy.pop();
                //if someone gets free then put them back in idle
                idle.push({server,idx});
            }

            //case where there is no free server
            if(idle.empty()){
                auto [time, server, idx] = busy.top();
                busy.pop();
                res[i] = idx;
                busy.push({time + tasks[i], server, idx});
            }
            else{
                auto [server, idx]= idle.top();
                idle.pop();
                res[i] = idx;
                busy.push({tasks[i]+i, server, idx});
            }
        }

        return res;

        
        
    }
};