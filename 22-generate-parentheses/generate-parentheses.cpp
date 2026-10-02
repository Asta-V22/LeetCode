class Solution {
public:
    vector<string> res;
    void solve(string cur, int open, int close,int n){
        if(cur.size()==2*n){
            res.push_back(cur);
            return;
        }
        if(open<n){
            cur.push_back('(');
            solve(cur,open+1, close, n);
            cur.pop_back();
        }

        if(close<open){
            cur.push_back(')');
            solve(cur,open,close+1,n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        int open = 0;
        int close= 0;
        solve(temp,open,close,n);
        return res;

    }
};