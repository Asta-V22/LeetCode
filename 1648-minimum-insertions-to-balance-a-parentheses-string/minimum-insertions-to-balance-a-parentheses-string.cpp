class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        stack<int> st;
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(i+1<n){
                    if(s[i+1]==')'){
                        if(st.empty()){
                            ans++;
                        }
                        else{
                            st.pop();
                        }
                        i+=2;
                        continue;
                    }
                    else{
                        if(st.empty()){
                            ans+=2;
                        }
                        else{
                            st.pop();
                            ans++;
                        }
                    }
                }
                else{
                    if(st.empty()){
                        ans+=2;
                    }
                    else{
                        st.pop();
                        ans++;
                    }
                }

            }
            i++;
            

            
        }   

        return 2*st.size()+ans;
    }
};