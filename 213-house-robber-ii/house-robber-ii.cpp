class Solution {
public:
    int n;
    int dp[105];
    int solve(vector<int> &nums, int i, int n){     //also giving n in order to limit the scope
        if(i>n){
            return 0;
        }   
        if(dp[i]!=-1) return dp[i];

        return dp[i] = max(solve(nums,i+2,n)+nums[i],solve(nums,i+1,n));
    }
    int rob(vector<int>& nums) {
        n = nums.size();

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);  
        memset(dp,-1,sizeof(dp));
        int chosefirst = solve(nums,0,n-2);
        memset(dp,-1,sizeof(dp));
        int choselast = solve(nums,1,n-1);

        return max(chosefirst, choselast);
    }
};