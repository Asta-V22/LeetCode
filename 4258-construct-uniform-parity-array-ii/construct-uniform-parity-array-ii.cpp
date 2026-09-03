class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //5,6,9,12,14,16
        //6,7,9,13,15
        //observation: if the first element is odd (in sorted array) then it doesn't matter what comes after it, we can change it into odd array, but if the first element is even then the entire must be even ahead, 
        //4,6,7,9,12,15

        sort(nums1.begin(), nums1.end());
        if(nums1[0]%2==0){
            for(int i=1; i<nums1.size(); i++){
                if(nums1[i]%2!=0) return false;
            }
        }
        return true;
    }
};