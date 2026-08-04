class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]!=1){
                int diff = nums[i]-nums[i-1];
                for(int j=1; j<diff; j++){
                    ans.push_back(nums[i-1]+j);
                }
            }
        }
        
        return ans;
    }
};