class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int l = 0;
    int maxLen = 0;

    vector<int> hash(256,-1);

    for(int r =0; r<n; r++){
        if(hash[s[r]] != -1){
            l = max(hash[s[r]] +1 , l);
        }
        hash[s[r]] = r;

        int len = r-l+1;

        maxLen = max(len, maxLen);

    }
    return maxLen;
    }
};