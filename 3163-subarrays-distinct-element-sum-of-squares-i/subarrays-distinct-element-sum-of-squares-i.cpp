class Solution {
public:
    int uniqueelements(vector<int>& arr){
        set<int> st;

        for(int i=0; i<arr.size(); i++){
            st.insert(arr[i]);
        }
        int s = st.size();
        return s*s;
    }
    int sumCounts(vector<int>& nums) {
       int n = nums.size();
       int res = 0;

       for(int i=0; i<n; i++){
        vector<int> curr;
        for(int j=i; j<n; j++){
            curr.push_back(nums[j]);
            res+=uniqueelements(curr);
        }
       }
       return res;
    }
};