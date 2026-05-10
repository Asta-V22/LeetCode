class Solution {
public:
    double f(double x, long long n){
        if(n==0){
            return 1;
        }
        else if(n==1){
            return x;
        }
        //if the power is even
        else if(n%2==0){
            return f(x*x,n/2);
        }
        //if n is odd
        else{
            return x*f(x*x , (n-1)/2);
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            N = -N;
            x = 1/x;
        }
        return f(x,N);
    }
};