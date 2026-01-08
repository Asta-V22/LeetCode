class Solution {
public:
    string removeKdigits(string num, int k) {
    int n = num.size();

    if(n==k) return "0";
    stack<int> st;

    for(int i =0; i<n; i++){
        while(!st.empty() && st.top()>num[i] && k>0){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
        while(k>0){
            st.pop();
            k--;
        }

    string res = "";
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    while(res.size()!=0 && res.back() == '0'){
        res.pop_back();
    }
    reverse(res.begin(),res.end());

    if(res.empty()) return "0";

    return res;
    }
};