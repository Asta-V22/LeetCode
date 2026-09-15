class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n] != -1) return dp[n];   //if it is already solved and in dp vector
        return dp[n] = solve(n-1, dp)+solve(n-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);

        return solve(n,dp);
    }
};