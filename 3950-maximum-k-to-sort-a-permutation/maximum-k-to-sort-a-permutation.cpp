class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1; // 11111...
        int res = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]!=i){
                k = k&nums[i];
            }
        }


        return (k==-1?0:k);
    }
};