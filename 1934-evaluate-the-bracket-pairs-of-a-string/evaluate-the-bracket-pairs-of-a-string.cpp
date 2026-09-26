class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;

        for(auto element: knowledge){
            mp[element[0]] = element[1];
        }

        string res = "";
        string key  = "";
        bool lastseen = false;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                lastseen = true;
                continue;
            }
            else if(s[i]==')'){
                lastseen = false;
                if(mp.find(key)!=mp.end()){
                    res+=mp[key];
                }
                else{
                    res+='?';
                }
                key = "";
                
                continue;
            }

            if(lastseen){
                key+=s[i];
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};