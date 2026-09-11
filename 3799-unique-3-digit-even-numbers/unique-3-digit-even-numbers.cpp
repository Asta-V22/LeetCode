class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        //absolute bruteforce
        int n = digits.size();
        unordered_set<int> st;
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j||j==k||i==k) continue;   //we do not want to process duplicates
                    int number = digits[i]*100 + digits[j]*10 + digits[k];
                    if(number>=100 && number%2==0){
                        st.insert(number);
                    }
                }
            }
        }
        return st.size();
    }
};