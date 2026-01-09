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
};