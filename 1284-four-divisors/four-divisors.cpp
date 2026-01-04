class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum =0;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            int cnt =0;
            int temp =0;
            for(int j=1; j*j<=n; j++){
                if(n%j==0){
                    int d1 =j;
                    int d2 =n/j;

                    if(d1==d2){  //perfect square
                        cnt++;
                        temp+=j;   
                    }
                    else{           //different number
                        cnt+=2;
                        temp += d1+d2;
                    }
                }
                if(cnt>4){
                    break;
                }
            }
            if(cnt==4){
                sum+=temp;
            }
        }
        return sum;
    }
};