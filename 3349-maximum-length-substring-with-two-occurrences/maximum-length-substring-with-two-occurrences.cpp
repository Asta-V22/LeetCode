class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        int count = 0;

        unordered_map<char, int> mp;

        for(int r=0; r<s.size(); r++){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
            count = max(count, r-l+1);
        }

        return count;
    }
};