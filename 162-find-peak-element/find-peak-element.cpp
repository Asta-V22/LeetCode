class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n-2;

        //cross out edge cases

        //if there is only 1 element in the array

        if(n==1) return 0;

        //if 0th index is the

        if(nums[0]>nums[1]) return 0;

        if(nums[n-2]<nums[n-1])  return n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;

            if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                low = mid +1;
            }
            else{
                high = mid-1;
            }

        }
        return -1;
    }
};