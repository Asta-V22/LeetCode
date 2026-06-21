class Solution {
public:

    int getFirstElement(vector<int>& nums, int target){
        int n = nums.size();
        int low =0; 
        int high = n-1;
        int first = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]> target){
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                first = mid;
                high = mid-1;
            }
        }
        return first;
    }
    int getLastElement(vector<int>& nums, int target){
        int n = nums.size();
        int low =0; 
        int high = n-1;
        int last = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]> target){
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                last = mid;
                low = mid+1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int a = getLastElement(nums, target);
        int b = getFirstElement(nums, target);

        return {b,a};
    }
};