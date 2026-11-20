class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int findnum(vector<int> &nums, int start, int target){
        int j = lower_bound(nums.begin()+start, nums.end(), target) - nums.begin();

        if(j<n && nums[j]==target){
            return j;
        }
        return -1;
    }

    int solve(int i, int del , vector<int>& nums){

        if(memo[i][del]!=-1){
            return memo[i][del];
        }
        int num = nums[i] + del;
        //now we need to find this num

        int length = 1;

        int j = findnum(nums,i+1,num+1);
        if(j!=-1){
            length = max(length,1+solve(j,0,nums));
        }

        j = findnum(nums, i+1, num);
        if(j!=-1){
            length = max(length,1+solve(j,1,nums));
        }
        return memo[i][del] = length;
          
    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        int result = 1;

        sort(nums.begin(), nums.end());

        memo.assign(n+1, vector<int>(2,-1));

        for(int i=0; i<n; i++){
            result = max({result, solve(i,0,nums), solve(i,1,nums)});
        }

        return result;
    }
};