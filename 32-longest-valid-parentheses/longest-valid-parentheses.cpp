class Solution {
public:
    int longestValidParentheses(string s) {
    int n = s.size(), best = 0;
    if (s.find(')') == string::npos) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int bal = 0;
        for (int j = i; j < n; j++) {
            bal += (s[j] == '(') ? 1 : -1;
            if (bal < 0) break;
            if (bal == 0) best = max(best, j - i + 1);
        }
    }
    return best;
}
};