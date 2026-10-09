class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int st = 0;
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                st++;
            }
            else if(s[i]==')'){
                if(i+1<n){
                    if(s[i+1]==')'){
                        if(st==0){
                            ans++;
                        }
                        else{
                            st--;
                        }
                        i+=2;
                        continue;
                    }
                    else{
                        if(st==0){
                            ans+=2;
                        }
                        else{
                            st--;
                            ans++;
                        }
                    }
                }
                else{
                    if(st==0){
                        ans+=2;
                    }
                    else{
                        st--;
                        ans++;
                    }
                }

            }
            i++;
            
        }   

        return 2*st+ans;
    }
};