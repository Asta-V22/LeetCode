class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();
        //BOTTOM UP
        vector<int> t(n+1);

        t[0]=0;   //loot from first 0 houses is 0
        t[1]=nums[0];   //loot from the first 1 house is nums[0]

        //now for the 2 houses we have two cases we may steal it or not
        for(int i=2; i<=n; i++){
            int steal = nums[i-1]+t[i-2];
            int skip = t[i-1];

            t[i] = max(steal,skip);
        }

        return t[n];
    }
};