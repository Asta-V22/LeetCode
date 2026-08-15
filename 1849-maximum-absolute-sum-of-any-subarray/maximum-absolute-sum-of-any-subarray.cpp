class Solution {
private:
    int maxSubarraySum(vector<int> &nums){
        int currMaxSubSum = nums[0];
        int currMinSubSum = nums[0];
        int maxSubSum = nums[0];
        int minSubSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            currMaxSubSum = max(nums[i], nums[i]+currMaxSubSum);
            currMinSubSum = min(nums[i], nums[i]+currMinSubSum);
            maxSubSum = max(maxSubSum, currMaxSubSum);
            minSubSum = min(minSubSum, currMinSubSum);
        }

        return max(abs(maxSubSum), abs(minSubSum));
    }

public:
    int maxAbsoluteSum(vector<int>& nums) {
        return maxSubarraySum(nums);
    }
};