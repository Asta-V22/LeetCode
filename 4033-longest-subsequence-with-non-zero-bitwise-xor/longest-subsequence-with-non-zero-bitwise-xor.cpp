class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // int numOfZeros = count(nums.begin(), nums.end(), 0);

        // if(numOfZeros==nums.size()) return 0;

        int xori = 0;
        bool hasNonZero = false;
        for(int i=0; i<nums.size(); i++){
            xori = xori^nums[i];
            if(nums[i]!=0) hasNonZero = true;
        }

        if(!hasNonZero){
            return 0;
        }

        if(xori!=0){
            return nums.size();
        }
        
        return nums.size()-1;
    }
};