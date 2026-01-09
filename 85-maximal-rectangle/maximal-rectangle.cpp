class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<int> st;

        for(int i =0; i<heights.size(); i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int element = st.top();
                int nse = i;
                st.pop();
                int pse = st.empty()?-1:st.top();

                maxi = max(maxi , heights[element]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = heights.size();
            int element = st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxi = max(maxi , heights[element]*(nse-pse-1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> prefixSum(row, vector<int>(col, 0));

        for(int j =0; j<=col-1; j++){
            int sum =0;
            for(int  i =0; i<=row-1; i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] == '0') sum =0;
                prefixSum[i][j] = sum;
            }
        }
        int maxi = 0;

        for(int i =0; i<row; i++){
            maxi = max(maxi , largestRectangleArea(prefixSum[i]));
        }
        return maxi;
    }
};