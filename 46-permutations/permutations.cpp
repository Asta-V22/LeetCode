class Solution {
public:
    void f(vector<int> &ds, vector<int> &state, vector<vector<int>> &ans, vector<int> &arr){
    if(ds.size()==arr.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if(state[i]==1) continue;
        ds.push_back(arr[i]);
        state[i]=1;
        f(ds,state,ans,arr);
        ds.pop_back();
        state[i]=0;
    }
}
     
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> state(nums.size(),0);

    f(ds,state,ans,nums);
    return ans;
}
    
};