class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        unordered_map<int,int> mp;
        for(int it : nums1){
            mp[it]++;
        }

        //now we have a record of every element of nums1 in our map
        for(auto it:nums2){
            if(mp[it]>0){
                ans.push_back(it);
                mp[it]--;
            }
        }

        return ans;
    }
};