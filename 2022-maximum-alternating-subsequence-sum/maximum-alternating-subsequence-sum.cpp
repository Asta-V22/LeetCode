class Solution {
public:
    int n;
    long long t[100001][2];
    long long solve(vector<int>& nums, int idx, bool flag){
        if(idx>=n){
            return t[idx][flag] = 0;
        }

        if(t[idx][flag]!=-1){
            return t[idx][flag];
        }

        long long nottake = solve(nums, idx+1, flag);
        long long  val = nums[idx];
        if(!flag){
            val=-val;
        }
        long long take = solve(nums, idx+1, !flag)+val;

        return t[idx][flag] = max(take, nottake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        int idx = 0;
        bool flag = true;
        return solve(nums,idx,flag);
    }
};