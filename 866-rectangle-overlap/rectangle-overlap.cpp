class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int p = rec1[2];
        int q = rec1[3];
        int r = rec1[0];
        int s = rec1[1];


        int k = rec2[2];
        int l = rec2[3];
        int m = rec2[0];
        int n = rec2[1];

        // if(r>=k || s>=l || p>=m || q>=n) return false;
        // return true;/

        if(r<k && s<l && m<p && n<q) return true;

        return false;
    }   
};