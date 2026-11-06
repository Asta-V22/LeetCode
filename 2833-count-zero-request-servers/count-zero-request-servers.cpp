class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        //FIRST WE GOTTA SORT the logs and the queries
        
        auto lambda = [](vector<int> vec1, vector<int> vec2){
            return vec1[1]<vec2[1];
        };

        sort(logs.begin(), logs.end(), lambda);

        //we will also sort queries but with their orginal indices preserved

        int q = queries.size();

        vector<int> res(q);   //in this we'll store the not visited servers
        vector<pair<int,int>> queries_sorted(q);

        for(int i=0; i<q; i++){
            queries_sorted[i] = {queries[i],i};
        }

        sort(queries_sorted.begin(), queries_sorted.end());

        unordered_map<int,int> mp;

        int i=0;
        int j=0;
        for(auto [time, idx] : queries_sorted){

            int start = time-x;
            int end = time;


            //check for j
            while(j<m && logs[j][1]<=end)
            {   
                mp[logs[j][0]]++;
                j++;
            }

            while(i<m && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
                
            }

            res[idx] = n - mp.size();
        }

        return res;

    }
};