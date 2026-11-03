class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        
        int res = 0;
        for(int &num: nums){
            res+=maxi-num;
        }

        return res;
    }
};