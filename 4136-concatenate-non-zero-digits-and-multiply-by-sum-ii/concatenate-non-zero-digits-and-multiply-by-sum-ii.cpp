class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // pow10[i] = 10^i % MOD
        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // sumD[i] = sum of digits in first i characters
        vector<int> sumD(n + 1, 0);

        // cntN0[i] = count of non-zero digits in first i characters
        vector<int> cntN0(n + 1, 0);

        // p[i] = number formed by concatenating all non-zero digits
        // in first i characters
        vector<long long> p(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d != 0);

            if (d != 0)
                p[i] = (p[i - 1] * 10 + d) % MOD;
            else
                p[i] = p[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int nonZero = cntN0[r + 1] - cntN0[l];

            int digitSum = sumD[r + 1] - sumD[l];

            long long x =
                (p[r + 1] -
                 p[l] * pow10[nonZero] % MOD +
                 MOD) % MOD;

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};