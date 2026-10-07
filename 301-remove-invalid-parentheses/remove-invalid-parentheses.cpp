class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int openRem = 0, closeRem = 0;
        for (char c : s) {
            if (c == '(') openRem++;
            else if (c == ')') {
                if (openRem > 0) openRem--;
                else closeRem++;
            }
        }

        vector<string> res;
        string path;
        dfs(s, 0, openRem, closeRem, 0, false, path, res);
        return res;
    }

private:
    void dfs(const string& s, int i, int openRem, int closeRem, int balance,
             bool prevRemoved, string& path, vector<string>& res) {
        int n = s.size();
        if (i == n) {
            if (openRem == 0 && closeRem == 0 && balance == 0)
                res.push_back(path);
            return;
        }
        if (openRem + closeRem > n - i) return;

        char c = s[i];

        bool canRemove = (i == 0 || s[i] != s[i - 1] || prevRemoved);
        if (canRemove) {
            if (c == '(' && openRem > 0)
                dfs(s, i + 1, openRem - 1, closeRem, balance, true, path, res);
            else if (c == ')' && closeRem > 0)
                dfs(s, i + 1, openRem, closeRem - 1, balance, true, path, res);
        }

        path.push_back(c);
        if (c == '(')
            dfs(s, i + 1, openRem, closeRem, balance + 1, false, path, res);
        else if (c == ')') {
            if (balance > 0)
                dfs(s, i + 1, openRem, closeRem, balance - 1, false, path, res);
        } else {
            dfs(s, i + 1, openRem, closeRem, balance, false, path, res);
        }
        path.pop_back();
    }
};