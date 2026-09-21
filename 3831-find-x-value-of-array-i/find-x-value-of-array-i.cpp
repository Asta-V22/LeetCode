class Solution {
public:
    typedef long long ll;

    vector<ll> resultArray(vector<int>& nums, int k) {
        vector<ll> res(k, 0);
        
        vector<ll> dp(k, 0);

        for (int x : nums) {
            vector<ll> next_dp(k, 0);
            ll current_rem = x % k;

            // 1. Extend all previous subarrays by multiplying with current element
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    ll new_rem = (r * current_rem) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // 2. Subarray of length 1 containing just the current element
            next_dp[current_rem]++;

            // 3. Add the subarrays ending at this position to our overall results
            for (int r = 0; r < k; r++) {
                res[r] += next_dp[r];
            }

            // Move to next step
            dp = move(next_dp);
        }

        return res;
    }
};