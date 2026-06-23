class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0; 
        int high = nums.size()-1;

        while(low<high){
            int mid = low + (high-low)/2;
            //we'll narrow down oursearch by finding in which part the smaller part is there, if the mid element is greater then high element then there will be smaller element between them, since we know that in a rotated array one of the part is bound to be sorted so the other will be sorted and greater then the end one so we can eleminate that part from that logic
            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};