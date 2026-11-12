class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int negSlope = 1;
        int posSlope = 1;

        int maxSlope = 1;
        
        for(int i=0; i<nums.size()-1; i++){
            if((nums[i+1]-nums[i]) > 0){
                posSlope++;
                negSlope=1;
                maxSlope = max(posSlope, maxSlope);
            } 
            else if((nums[i+1]-nums[i]) < 0){
                negSlope++;
                posSlope = 1;
                maxSlope = max(negSlope, maxSlope);
            }
            else{
                negSlope = 1;
                posSlope = 1;
            }

            

        }
        
        return maxSlope;
    }
};