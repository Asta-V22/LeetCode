class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> duplicate = arr;

        sort(duplicate.begin(), duplicate.end());


        unordered_map<int,int> mp;
        int r =1;
        for(int x : duplicate){
            if(mp.find(x) == mp.end()){
                //if no entry in the map yet
                mp[x] = r++;
            }
        }

        for(int i=0; i<arr.size();i++){
            arr[i] = mp[arr[i]];            
        }

        return arr;

    }
};