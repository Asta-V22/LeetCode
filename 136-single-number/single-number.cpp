class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr =0;
        for(int i =0; i<nums.size(); i++){
            xorr = xorr^nums[i];  //property: a^a = 0 and 0^a = a, so at the end only the single element remain
        }
        return xorr;
    }
};