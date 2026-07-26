class Solution {
public:
    int cstairs(int n, vector<int> &dp){
        if(n==0) return 1;
        if(n==1) return 1;

        
        if(dp[n] != -1) return dp[n];

        return dp[n] = cstairs(n-1, dp) + cstairs(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return cstairs(n,dp);
    }
};