class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        //BRUTE FORCE

        // int count =0 ;

        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum+= arr[j];
        //         if(sum%2!=0) count++;
        //     }
        // }

        // return count;


        //Optimal
        int M = 1e9 + 7;


        //even+odd = odd and odd+even = odd  , so basically for every even or odd occurences we have to find the alternate previous occurences so that the above cases makes sense
        int even = 1;   //because 0 is even, we'll add it for including the odd number themselves
        int odd = 0;
        int result = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum%2==0){
                result= (result+odd)%M;
                even++;
            }
            else{
                result=(result+even)%M;
                odd++;
            }
        }

        return result%M;
    }
};