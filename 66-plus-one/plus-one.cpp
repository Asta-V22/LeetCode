class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size()-1;
        if(digits[l]!=9 ){
            digits[l]++;
            return digits;
        }
        else{
            for(int i = l; i>=0; i--){
                if(digits[i] == 9){
                    digits[i] =0;
                }
                else{
                    digits[i]++;
                    return digits;
                }
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};