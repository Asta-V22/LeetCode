class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n){
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        if(k==1){
            sort(nums.begin(), nums.end());
            for(int i=n-1; i>=0; i--){
                if(mp[nums[i]]==1){
                    return nums[i];
                }
            }
        }

        //for 1<k<n
        if(mp[nums[0]]>1 && mp[nums[n-1]]>1){
            return -1;
        }
        else if(mp[nums[0]]==1 && mp[nums[n-1]]==1){
            return max(nums[0], nums[n-1]);
        }
        else if(mp[nums[n-1]]>1){
            return nums[0];
        }
        else if(mp[nums[0]]>1){
            return nums[n-1];
        }
        return -1;
    }
};