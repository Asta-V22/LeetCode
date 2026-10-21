class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin(), s.end())){
            return 0;
        }

        if(n==2) return -1;

        char start = *min_element(s.begin(), s.end());
        char end  = *max_element(s.begin(), s.end());

        if(s[0]==start || s[n-1]==end){
            return 1;
        }

        for(int i=1; i<n-1; i++){
            if(s[i]==start || s[i]==end){
                return 2;
            }
        }

        return 3;
    }
};