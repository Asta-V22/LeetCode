class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int k = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool inc = true, dec = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != ((i - k) % n + n) % n) inc = false;  // rotation of sorted
            if (nums[i] != ((k - i) % n + n) % n) dec = false;  // rotation of reversed
        }

        long long ans = LLONG_MAX;
        if (inc) ans = min<long long>(ans, min(k, n - k + 2));
        if (dec) ans = min<long long>(ans, min(n - k, (k + 1) % n + 1));

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};