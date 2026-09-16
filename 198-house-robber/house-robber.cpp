class Solution {
public:
    int n;
    int dp[102];
    int solve(vector<int>& nums,int i,int dp[]){
        if(i>=n){
            return dp[i]=0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(solve(nums,i+2,dp)+nums[i], solve(nums,i+1,dp));

    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,dp);
    }
};