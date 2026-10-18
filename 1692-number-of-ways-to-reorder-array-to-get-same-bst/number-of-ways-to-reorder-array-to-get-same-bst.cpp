class Solution {
public:
    int n;
    typedef long long ll;
    ll MOD = 1e9+7;

    vector<vector<ll>> PT;

    ll solve(vector<int> &nums){
        int m = nums.size();
        if(m<3){
            return 1;
        }
        vector<int> left_arr;
        vector<int> right_arr;

        int root = nums[0];
        for(int i=1; i<m; i++){
            if(nums[i]<root){
                left_arr.push_back(nums[i]);
            }
            else{
                right_arr.push_back(nums[i]);
            }
        }

        ll x = solve(left_arr)%MOD;
        ll y = solve(right_arr)%MOD;

        ll z = PT[m-1][left_arr.size()];   //we can also take right_arr.size() it does not matter

        return (((x*y)%MOD)*z)%MOD;
    }
    int numOfWays(vector<int>& nums) {
        n = nums.size();

        PT.resize(n+1);

        //populating the pascal's triangle
        for(int i=0; i<n; i++){
            PT[i] = vector<ll>(i+1,1);

            for(int j=1; j<i; j++){
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1])%MOD;
            }

        }

        return (solve(nums)-1 +MOD)%MOD;
    }
};