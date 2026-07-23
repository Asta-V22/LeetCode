class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int l=0;
       int count =1;
       for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[l]){
                l++;
                swap(nums[l],nums[i]);
                count++;
            }
            
       }
       return count;
    }
};