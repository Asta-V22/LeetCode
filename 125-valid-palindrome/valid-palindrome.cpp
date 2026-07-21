class Solution {
public:
    bool isPalindrome(string s){

    for(int i = 0; i<s.size(); i++){
        if(!isalnum((unsigned char)s[i])){
            s.erase(i,1);
            i--;
        }
    }



    for(auto& c: s  ){            //by putting & it will change the content of the string
        c = tolower(c);
    }  

    int start = 0;
    int end = s.size() - 1;

    while(start<end){
        if(s[start] == s[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }

    return true;
    
    
}

};