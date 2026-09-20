class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;
        for(int i=0; i<s.size(); i++){
            int val = 26 - (s[i]-'a');
            int product = val*(i+1);
            degree+=product;

        }
        return degree;
    }
};