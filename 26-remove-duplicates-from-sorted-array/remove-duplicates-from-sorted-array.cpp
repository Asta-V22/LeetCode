class Solution {
public:
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int count = 1;

        for(int i=1; i<n; i++){
            if(nums[l]==nums[i]) continue;
            count++;
            l++;
            swap(nums[l],nums[i]);
        }
        return count;
    }
};