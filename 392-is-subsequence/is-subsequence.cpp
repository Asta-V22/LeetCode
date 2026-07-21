class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.size();
        int lent = t.size();

        if(lens>lent) return false;

        int a = 0;
        int b =0;
        while(a<lens && b<lent){
            if(s[a]==t[b]){
                a++;
                b++;
            }
            else if(s[a]!=t[b]){
                b++;
            }
        }

        if(a==lens) return true;

        return false;

    }
};