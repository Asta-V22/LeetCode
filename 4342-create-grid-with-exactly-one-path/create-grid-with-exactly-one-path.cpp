class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        string first(n,'.');
        res.push_back(first);

        for(int i=1; i<m; i++){
            string nxt = string(n-1,'#') + '.';
            res.push_back(nxt);
        }

        return res;
    }
};