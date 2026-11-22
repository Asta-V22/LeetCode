class Solution {
public:
    bool checkString(string s) {
        int idxa = -1;
        int idxb = -1;
        int flag = true;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='a'){
                idxa = i;
            }
            if(flag && s[i]=='b'){
                idxb = i;
                flag = false;
            }
        }

        if(idxb==-1) return true;

        if(idxa < idxb){
            return true;
        }
        return false;
    }
};