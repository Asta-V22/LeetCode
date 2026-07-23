class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m;
        
        for(int i=0; i<n; i++){
            nums1[l]=nums2[i];
            l++;
        }

        sort(nums1.begin(),nums1.end());

        
    }
};