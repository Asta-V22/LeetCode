class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        //let us make a vector that will store the min element from i to n-1 each i
        vector<int> min_array(n);

        int mini = INT_MAX;
        for(int i=n-1; i>=0; i--){
            mini = min(mini,nums[i]);
            min_array[i]=mini;
        }

        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);
            if(maxi-min_array[i]<=k) return i;
        }

        return -1;
    }
};