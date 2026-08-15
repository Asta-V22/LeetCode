class Solution {
private:
    int maxSubarraySum(vector<int> nums){
        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            currSubSum = max(nums[i], nums[i]+currSubSum);
            maxSubSum = max(maxSubSum, currSubSum);
        }

        return maxSubSum;
    }

    int minSubarraySum(vector<int> nums){
        int currSubSum = nums[0];
        int minSubSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            currSubSum = min(nums[i], nums[i]+currSubSum);
            minSubSum = min(minSubSum, currSubSum);
        }

        return minSubSum;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(minSubarraySum(nums)), abs(maxSubarraySum(nums)));
    }
};