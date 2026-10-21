class Solution {
public:
    int minOperations(string s) {
        //if the size of the string 1 then it is already sorted
        int n = s.size();
        if(n == 1) return 0;

        //first check if the string is already sorted
        bool alreadysorted = true;
        for(int i=1; i<n; i++){
            if(s[i]<s[i-1]){
                alreadysorted = false;
                break;
            }
        }

        if(alreadysorted) return 0;

        //if the size of the string is 2
        if(n==2 && alreadysorted==false) return -1;

        //now we can cater for the cases where size is 3 or more

        string s_ = s;
        sort(s_.begin(), s_.end());
        //case 1: any one of the greatest or smallest is at its correct position
        if(s_[0]==s[0] || s_[n-1] == s[n-1] ){
            return 1;
        }

        //if the copies of the max or min element exists anywhere other then extremities
        for(int i=1; i<n-1; i++){
            if(s[i]==s_[0] || s[i]==s_[n-1]){
                return 2;
            }
        }

        //for all the rest cases
        return 3;
        
        
    }
};