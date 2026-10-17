class Solution {
public:
    int getdigsum(int num){
        int sum = 0;
        while(num>0){
            int digit = num%10;
            sum+=digit;
            num = num/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> postsort(nums);

        auto lambda = [&](int num1, int num2){
            int digsum1 = getdigsum(num1);
            int digsum2 = getdigsum(num2);

            if(digsum1!=digsum2){
                return digsum1<digsum2;
            }
            return num1<num2;
        };

        sort(nums.begin(), nums.end(), lambda);

        //map the original places in a map

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }

        //now we can calculate the swap req
        int swapcount = 0;
        for(int i=0; i<n; i++){
            int intended = postsort[i];
            int realval = nums[i];

            if(intended == realval) continue;

            int idx= mp[intended];

            nums[i] = intended;
            nums[idx] = realval;

            mp[intended] = i;
            mp[realval] = idx;

            swapcount++;
               
        }

        return swapcount;
    }
};