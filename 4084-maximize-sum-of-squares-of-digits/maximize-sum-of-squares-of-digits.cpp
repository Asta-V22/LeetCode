class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        if(sum<10){
            res+=to_string(sum);
            num--;
            while(num--){
                res+="0";
            }
            return res;
        }

        res+="9";
        num--;
        sum-=9;

        while(num--){
            if(sum-9 > 0){
                res+="9";
                sum-=9;
            }
            else{
                res+=to_string(sum);
                sum = 0;
            }
        }

        if(sum>0) return "";


        return res;
    }
};