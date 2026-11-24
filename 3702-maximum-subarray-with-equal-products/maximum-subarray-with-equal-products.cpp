#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lcmVal(int a, int b) {
        return (a / std::gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        const int MAX_LCM_GCD = 2520 * 10; // 25,200

        for (int i = 0; i < n; i++) {
            int prod = 1;
            int curGcd = 0;
            int curLcm = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod > MAX_LCM_GCD) break;

                curGcd = std::gcd(curGcd, nums[j]);
                curLcm = lcmVal(curLcm, nums[j]);

                if (prod == curLcm * curGcd) {
                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};