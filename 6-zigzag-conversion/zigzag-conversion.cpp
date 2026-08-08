class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

        string ans = "";

        for(int i=0; i<numRows; i++){
            int increment = 2*(numRows-1);
            for(int j=i; j<s.size(); j=j+increment){
                ans+=s[j];
                if(i>0 && i<numRows-1 && j+increment-2*i < s.size()){
                    ans+=s[j+increment-2*i];
                }
            }
        }

        return ans;
    }
};