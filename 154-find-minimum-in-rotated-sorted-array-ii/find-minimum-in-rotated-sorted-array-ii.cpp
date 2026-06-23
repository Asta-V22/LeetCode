class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else if(nums[mid]<nums[high]){
                high = mid;
            }
            else{    //this is the part that is different form Q 153
                high--; 
                
                /*high is not giving any useful info so we simply remove that, why not low++? in out if conditions we are only checking mid and high, we have no clue of what low is, so we cannot remove it from our search space recklessly 
                */
            }
        }
        return nums[low];
    }
};