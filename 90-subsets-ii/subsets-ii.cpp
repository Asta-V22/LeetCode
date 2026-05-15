class Solution {
public:


    void f(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr, int n){        
        ans.push_back(ds);
        
        for(int i = ind; i<n; i++){
            if(i>ind && arr[i-1]==arr[i]){
                continue;
            }
            ds.push_back(arr[i]);
            f(i+1,ds,ans,arr,n);
            ds.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        f(0,ds,ans,nums,n);
        return ans;
    }
};