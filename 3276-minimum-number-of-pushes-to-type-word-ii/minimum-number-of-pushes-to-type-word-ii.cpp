class Solution {
public:
    int minimumPushes(string word) {

        unordered_map<char,int> mp;

        for(char ch : word)
            mp[ch]++;

        vector<int> freq;

        for(auto &it : mp)
            freq.push_back(it.second);

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for(int i = 0; i < freq.size(); i++) {
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};