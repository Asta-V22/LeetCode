class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        //let us store the minimum value ahead in some other array
        vector<int> min_array(n);
        int mini = INT_MAX;
        for(int i=n-1; i>=0; i--){
            min_array[i] = min(mini,nums[i]);
            mini = min_array[i];
        }

        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);
            int stability_score = maxi - min_array[i];
            if(stability_score<=k){
                return i;
            }
        }
        return -1;
    }
};