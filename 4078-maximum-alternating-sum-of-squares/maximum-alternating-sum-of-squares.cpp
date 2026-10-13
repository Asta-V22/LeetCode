class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
            }
        }

        sort(nums.begin(), nums.end(), greater<int>());

        int m = (n+1)/2;

        long long res = 0;
        for(int i=0; i<n; i++){
            if(i<m){
                res+= 1LL*nums[i]*nums[i];
            }
            else{
                res-=1LL*nums[i]*nums[i];
            }
        }

        return res;
    }
};