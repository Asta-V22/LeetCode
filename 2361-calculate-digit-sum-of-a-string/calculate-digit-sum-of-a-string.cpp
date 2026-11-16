class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(s.size()>k){
            int sum = s[0] - '0';
            string temp = "";
            for(int i=1; i<s.size(); i++){
                if(i%k==0){
                    temp+=to_string(sum);
                    sum = 0;
                }
                int num = s[i]  - '0';
                sum+=num;
            }
            temp+=to_string(sum);
            s = temp;
        }

        return s;
    }
};