class Solution {
private:
    typedef unsigned long long ull;
    ull dp[1001][1001];
    ull number(string s, string &t, int i, int j){
        if(j==0) return dp[i][j] = 1;
        if(i==0) return dp[i][j]= 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i-1]==t[j-1]){
            return dp[i][j] = number(s,t,i-1,j-1) + number(s,t,i-1,j);
        }
        else{
            return dp[i][j]= number(s,t,i-1,j);
        }

        return -1;
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return number(s,t,s.size(),t.size());
    }
};