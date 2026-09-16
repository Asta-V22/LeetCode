/*-----------------DP WITH MEMOIZANTION------------------------*/


class Solution {
public:
    int solve(int i, int n, int &ways, vector<int> &dp){
        //i is how many steps we have already covered
        if(i==n){
            ways++;
            return 1;
        }
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = solve(i+1, n, ways,dp) + solve(i+2,n,ways,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        int ways = 0;
        return solve(0,n,ways,dp);
    }
};