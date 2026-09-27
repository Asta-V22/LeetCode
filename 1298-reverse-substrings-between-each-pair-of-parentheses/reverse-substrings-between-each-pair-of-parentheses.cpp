class Solution {
public:
    void revstring(string &input){
        int l=0;
        int r = input.size()-1;
        while(l<r){
            char temp = input[l];
            input[l] = input[r];
            input[r] = temp;
            l++;
            r--;
        }
    }
    string reverseParentheses(string s) {
        stack<int> st;

        int l =0;

        while(l<s.size()){
            if(s[l]=='('){
                st.push(l);
            }
            if(s[l]==')'){
                int t =st.top();
                st.pop();
                int i = t+1;
                int j = l-1;

                string rev = s.substr(i,j-i+1);
                revstring(rev);
                s.replace(t,l-t+1, rev);
                l--;
                continue;
            }
            l++;
        }
        return s;
    }
};