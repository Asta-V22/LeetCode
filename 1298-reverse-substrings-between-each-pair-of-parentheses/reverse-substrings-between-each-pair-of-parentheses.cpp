//Wormhole Teleportation technique
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<int> st;
        vector<int> v(n,-1);
        string res = "";

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                int idx = st.top();
                st.pop();

                v[i] = idx;
                v[idx] = i;
            }
        }



        bool l2r = true;
        int l = 0;
        while(l>=0 && l<s.size()){
            if(s[l]=='(' || s[l]==')' ){
                l=v[l];
                l2r = l2r?false:true;
            }
            else {
                res += s[l];
            }

            if (l2r)
                l++;
            else
                l--;
        }
        return res;
    }
};