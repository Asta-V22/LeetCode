class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int numOfZeros = count(nums.begin(), nums.end(), 0);

        if(numOfZeros==nums.size()) return 0;

        int xori = 0;
        for(int i=0; i<nums.size(); i++){
            xori = xori^nums[i];
        }

        if(xori!=0){
            return nums.size();
        }
        
        return nums.size()-1;
    }
};