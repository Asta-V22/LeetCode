class Solution {
public:
    string reverseWords(string s) {
        int l =0;
        int r =0;

        vector<string> v;
        string temp =""; 
        for(char ch: s){     
            if(ch!=' '){
                temp+=ch;        
            }
            else if(!temp.empty()){
                v.push_back(temp);
                temp ="";
            }
            
        }
        if(!temp.empty()) v.push_back(temp);

        //reverse the array
        reverse(v.begin(), v.end());

        string res = "";
        for(int i=0; i<v.size(); i++){
            res +=v[i];

            if(i<v.size()-1){
                res+=" ";
            }
        }

        return res;
    }
};