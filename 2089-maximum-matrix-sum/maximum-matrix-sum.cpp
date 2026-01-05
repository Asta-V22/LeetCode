class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        //critical observation : If the number of negative numbers are even than it can be added directly else put - sign at the least one
        int negative =0;
        long long sum =0;
        int min = INT_MAX;
        for(const auto& row : matrix ){
            for(const auto& element : row){
                if(element<0){
                    negative++;
                }
                if(abs(element)<min){
                    min = abs(element);
                }
                sum+= abs(element);
            }
        }
        if(negative%2==0){
            return sum;
        }
        else{
            return sum - 2*min;
        }
    }
};