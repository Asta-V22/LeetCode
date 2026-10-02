class Solution {
public:
    vector<string> res;
    bool isvalid(string s){
        int valid = 0;
        for(int i=0;i<s.size(); i++){
            if(s[i]=='('){
                valid++;
            }
            else if (s[i]==')'){
                valid--;
            }
            if(valid<0) return false;
        }
        if(valid==0) return true;
        return false;
    }
    void solve(string cur, int n){
        if(cur.size()==2*n){
            if(isvalid(cur)){
                res.push_back(cur);
            }
            return;
        }
        cur.push_back('(');
        solve(cur,n);
        cur.pop_back();

        cur.push_back(')');
        solve(cur,n);
        cur.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(temp,n);
        return res;

    }
};