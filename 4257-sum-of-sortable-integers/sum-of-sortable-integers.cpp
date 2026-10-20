class Solution {
public:
    bool ok(const vector<int>& a, int k) {
        int n = a.size();
        int prevMax = 0;                  
        for (int s = 0; s < n; s += k) {
            int drops = 0;
            int mn = a[s], mx = a[s];
            for (int i = s; i < s + k - 1; i++) {
                if (a[i] > a[i + 1]) drops++;
                mn = min(mn, a[i + 1]);
                mx = max(mx, a[i + 1]);
            }
            if (drops > 1) return false;
            if (drops == 1 && a[s + k - 1] > a[s]) return false;
            if (mn < prevMax) return false;
            prevMax = mx;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int k = 1; k <= n; k++)
            if (n % k == 0 && ok(nums, k)) res += k;
        return res;
    }
};