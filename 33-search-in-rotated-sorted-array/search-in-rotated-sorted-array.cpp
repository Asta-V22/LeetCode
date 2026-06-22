class Solution {
public:
    int search(vector<int>& nums, int target) {
        //this problem is totally based on the fact that in this scenario if we
        //do BS here then either one of the sides from the mid will be sorted, so we can get a clue from there that on which side our desired element is

        int low = 0;
        int high = nums.size() -1;

        while(low<=high){
            int mid = low + ( high - low)/2;
            if(nums[mid]==target) return mid;

            //else check which part is sorted and find in them if so

            //left side is sorted
            if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            //else right side is sorted
            else{
                if(target>nums[mid] && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }

        return -1;
    }
};