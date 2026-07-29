class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixmul(n);
        vector<int> suffixmul(n);

        prefixmul[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixmul[i] = prefixmul[i-1]*nums[i];
        }

        suffixmul[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffixmul[i]=suffixmul[i+1]*nums[i];
        }

        vector<int> ans(n);
        ans[0] = suffixmul[1];
        ans[n-1] = prefixmul[n-2];
        for(int i=1; i<n-1; i++){
            ans[i] = prefixmul[i-1]*suffixmul[i+1];
        }

        return ans;
    }
};