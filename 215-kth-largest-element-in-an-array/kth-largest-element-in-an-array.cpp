class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
           map<int, int> mp;

           for(int i=0; i<nums.size(); i++){
                mp[nums[i]]++;
           }
           //now all our elements are mapped to their number of occurences

           for(auto it = mp.rbegin(); it!=mp.rend(); ++it){
                    k-=it->second;
                    if(k<=0){
                        return it->first;
                    }
           }
           return -1;
    }
};