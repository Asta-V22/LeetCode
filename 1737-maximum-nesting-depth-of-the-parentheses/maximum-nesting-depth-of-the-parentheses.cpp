class Solution {
public:
    int maxDepth(string s) {
        int maxi = INT_MIN;
        int braces = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                braces++;
            }
            else if(s[i]==')'){
                braces--;
            }
            maxi = max(braces, maxi);
        }
        return maxi;
    }
};