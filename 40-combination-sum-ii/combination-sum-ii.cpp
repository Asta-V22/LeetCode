class Solution {
public:

    void f(int ind, int target, vector<int> &ds, vector<int>& arr, vector<vector<int>>& ans ){
        //base condition
            if(target==0){
                ans.push_back(ds);
                return;
            }
            

        for(int i=ind; i<arr.size(); i++){
            if(i>ind && arr[i-1]==arr[i]) continue;
            if(target<arr[i]) break;
            ds.push_back(arr[i]);
            f(i+1,target-arr[i],ds,arr,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        f(0,target,ds, candidates,ans);

        return ans;
        
    }
};