class Solution {
public:
    long long MOD = 1e9 + 7;

    long long f(long long x , long long n){
        if(n==0){
            return 1;
        }
        x = x%MOD;
        if(n%2==0){
            return (f((x*x)%MOD,n/2));
        }
        else{
            return (x*(f((x*x)%MOD, (n-1)/2)))%MOD;
        }
    }
    int countGoodNumbers(long long n) {
        //we know that even places 5 values can come and at odd places 4 values
        if(n==1){
            return 5;
        }
        long long N = n/2;
        long long ans = (f(4,N)*f(5,N))%MOD;
        if(n%2==0){
            return ans;
        }
        else{
            return (5*ans)%MOD;
        }
    }
};