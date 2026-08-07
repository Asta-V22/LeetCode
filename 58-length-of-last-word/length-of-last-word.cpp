class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        
        while(isspace(s[n])){
            n--;
        }
        int length = 0;
        for(int i=n; i>=0; i--){
            if(isspace(s[i])){
                break;
            }
            length++;
        }

        return length;
    }
};