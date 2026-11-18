class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        int i= 1;
        while(i<s.size()){
            if(s[i]!=s[i-1]) changes++;
            i+=2;
        }
        return changes;
    }
};