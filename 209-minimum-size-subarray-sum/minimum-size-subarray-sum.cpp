class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0;

        int minlen = INT_MAX;
        int sum = 0;

        for(int j=0; j<nums.size(); j++){
            sum+=nums[j];

            //note the length till it is greater than the target
            while(sum>=target){
                minlen=  min(minlen, j-i+1);
                sum-=nums[i];
                i++;
            }
        }

        return minlen==INT_MAX?0:minlen;
    }
};