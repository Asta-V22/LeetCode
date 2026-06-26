class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int l =0;
        int r = 0;
        long long total =0;
        int size = 1;

        while(r<nums.size()){
            total+=(long long)nums[r];
           while((long long)nums[r]*(r-l+1)>total+k){
            total-=(long long)nums[l];
            l++;
           }
           size = max(size, (r-l+1));
           r++;
        }

        return size;

    }
};